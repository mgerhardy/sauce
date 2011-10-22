#ifndef SAUCE_SAUCE_INTERNAL_BINDING_H_
#define SAUCE_SAUCE_INTERNAL_BINDING_H_

#include <map>
#include <set>
#include <vector>
#include <utility>

#include <cassert>

#include <sauce/exceptions.h>
#include <sauce/memory.h>
#include <sauce/named.h>
#include <sauce/internal/key.h>
#include <sauce/internal/type_id.h>

namespace sauce {

class Injector;

namespace internal {

template<typename Dependency>
class Binding;

struct OpaqueBinding;

typedef SAUCE_SHARED_PTR<OpaqueBinding> OpaqueBindingPtr;

/**
 * An opaque binding.
 *
 * Bindings associate an interface with an implementation.  How that provision
 * comes about is determine by derived types.  Binding itself is a pure
 * interface.
 *
 * To be type-homogenous, Binding is not a template, and particularly not a
 * template of any specific interface or implementation types.  It however has
 * a TypeId, which indirectly identifies the interface it is bound to.
 *
 * The interface is raised to the type system in Binding, a templated class
 * deriving from OpaqueBinding.  The implementation is in turn raised in
 * TransparentBinding, which derives from Binding.
 *
 * Other binding implementations (those that implement provision strategies)
 * extend TransparentBinding.  Their behavior is exposed to a Binding client
 * by (runtime) polymorphism.
 */
struct OpaqueBinding {

  /**
   * The TypeId of the (hidden) provided dependency.
   *
   * The dependency id finger prints which provision requests we can satisfy in an Injector.
   */
  virtual TypeId getDependencyId() = 0;

  /**
   * The TypeId of our (hidden) scope.
   */
  virtual TypeId getScopeId() = 0;

  /**
   * Provide, but do not return an instance of the hidden interface.
   *
   * Instead, cache the instance in its appropriate scope, if any.  If the binding is not scoped,
   * do nothing.  The typeIds indicate which keys are already currently being provided to detect
   * circular dependencies.
   */
  virtual void eagerlyProvide(OpaqueBindingPtr, Injector &, TypeIds &) {}

};

/**
 * A binding for a specific interface.
 */
template<typename Dependency>
struct Binding:
  public OpaqueBinding {

  typedef SAUCE_SHARED_PTR<Binding<Dependency> > BindingPtr;

  /**
   * Get an instance of Iface, using the given injector to provide dependencies.
   *
   * The binding pointer must point to this same binding instance.
   *
   * The typeIds indicate which keys are already currently being provided to detect circular
   * dependencies.
   */
  virtual typename Key<Dependency>::Ptr get(BindingPtr, Injector &, TypeIds &) = 0;

};

/**
 * Cast an OpaqueBindingPtr to a Binding smart pointer.
 *
 * This must be done carefully (with static_pointer_cast) in order to not lose the ref count.
 */
template<typename Dependency>
SAUCE_SHARED_PTR<Binding<Dependency> > resolve(OpaqueBindingPtr binding) {
  assert((typeIdOf<Dependency>()) == binding->getDependencyId());
  return SAUCE_STATIC_POINTER_CAST<Binding<Dependency> >(binding);
}

typedef void (*PendingThrow)();

/**
 * Template function used to create typed, deferred exceptions.
 *
 * The exception must have an accessible nullary constructor.
 * Template instantiations will construct and throw an instance.
 */
template<typename Exception>
void pendingThrowFactory() {
  throw Exception();
}

class Bindings {
  typedef std::map<TypeId, OpaqueBindingPtr> BindingMap;
  typedef std::vector<OpaqueBindingPtr> ScopedBindings;
  typedef std::map<TypeId, ScopedBindings> ScopeMap;

  BindingMap bindingMap;
  ScopeMap scopeMap;
  PendingThrow pending;

public:

  Bindings():
    bindingMap(),
    scopeMap(),
    pending(NULL) {}

  /**
   * Insert the given binding.
   */
  template<typename Binding_>
  void put() {
    OpaqueBindingPtr binding(new Binding_());
    bindingMap.insert(std::make_pair(binding->getDependencyId(), binding));
    TypeId scopeKey = binding->getScopeId();

    ScopeMap::iterator i = scopeMap.find(scopeKey);
    if (i == scopeMap.end()) {
      ScopedBindings scopedBindings;
      scopedBindings.push_back(binding);
      scopeMap.insert(i, std::make_pair(scopeKey, scopedBindings));
    } else {
      i->second.push_back(binding);
    }
  }

  /**
   * Provide the named Dependency.
   *
   * If no binding is found, throw UnboundException.
   */
  template<typename Dependency>
  typename Key<Dependency>::Ptr get(Injector & injector, TypeIds & typeIds) {
    std::map<TypeId, OpaqueBindingPtr>::iterator i = bindingMap.find(typeIdOf<Dependency>());
    if (i == bindingMap.end()) {
      throw UnboundExceptionFor<Dependency>();
    }

    SAUCE_SHARED_PTR<Binding<Dependency> > binding = resolve<Dependency>(i->second);
    return binding->get(binding, injector, typeIds);
  }

  template<typename Scope>
  void eagerlyProvide(Injector & injector, TypeIds & typeIds) {
    ScopeMap::iterator i = scopeMap.find(typeIdOf<Scope>());
    if (i == scopeMap.end()) {
      return;
    }

    ScopedBindings & scopedBindings = i->second;
    for (ScopedBindings::iterator i = scopedBindings.begin(); i != scopedBindings.end(); ++i) {
      OpaqueBindingPtr binding = *i;
      binding->eagerlyProvide(binding, injector, typeIds);
    }
  }

  /**
   * Save an exception of the given type to throw when it is safe.
   *
   * The exception must have an accessible nullary constructor.
   *
   * Any previously saved exception is dropped.
   */
  template<typename Exception>
  void throwLater() {
    pending = &pendingThrowFactory<Exception>;
  }

  /**
   * Throw and clear any saved exception.
   */
  void throwAnyPending() {
    if (pending) {
      PendingThrow toThrow = pending;
      pending = NULL;
      toThrow();
    }
  }
};

}

namespace i = ::sauce::internal;

}

#endif // SAUCE_SAUCE_INTERNAL_BINDING_H_
