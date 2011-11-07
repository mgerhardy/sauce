// This file was GENERATED by command:
//     pump.py new_binding.h.pump
// DO NOT EDIT BY HAND!!!

#ifndef SAUCE_SAUCE_INTERNAL_BINDINGS_NEW_BINDING_H_
#define SAUCE_SAUCE_INTERNAL_BINDINGS_NEW_BINDING_H_

#include <sauce/injector.h>
#include <sauce/memory.h>
#include <sauce/named.h>
#include <sauce/provider.h>
#include <sauce/internal/binding.h>
#include <sauce/internal/bindings/naked_binding.h>
#include <sauce/internal/bindings/transparent_binding.h>
#include <sauce/internal/key.h>
#include <sauce/internal/type_id.h>

namespace sauce {
namespace internal {
namespace bindings {

template<typename Dependency, typename Scope, typename Constructor,
    typename Allocator>
class NewBinding;

template<typename Dependency, typename Scope, typename Impl, typename Allocator>
struct NewBinding<Dependency, Scope, Impl(),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector>, TypeIds &) const {}

  Iface * provide(sauce::shared_ptr<Injector>) const {
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl();
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1>
struct NewBinding<Dependency, Scope, Impl(A1),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2>
struct NewBinding<Dependency, Scope, Impl(A1, A2),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3>
struct NewBinding<Dependency, Scope, Impl(A1, A2, A3),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
    this->template validateAcyclicos<A3>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getDependency<A3>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2, a3);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4>
struct NewBinding<Dependency, Scope, Impl(A1, A2, A3, A4),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
    this->template validateAcyclicos<A3>(injector, ids);
    this->template validateAcyclicos<A4>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getDependency<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getDependency<A4>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2, a3, a4);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5>
struct NewBinding<Dependency, Scope, Impl(A1, A2, A3, A4, A5),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
    this->template validateAcyclicos<A3>(injector, ids);
    this->template validateAcyclicos<A4>(injector, ids);
    this->template validateAcyclicos<A5>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getDependency<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getDependency<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getDependency<A5>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2, a3, a4, a5);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6>
struct NewBinding<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
    this->template validateAcyclicos<A3>(injector, ids);
    this->template validateAcyclicos<A4>(injector, ids);
    this->template validateAcyclicos<A5>(injector, ids);
    this->template validateAcyclicos<A6>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getDependency<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getDependency<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getDependency<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getDependency<A6>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2, a3, a4, a5, a6);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7>
struct NewBinding<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
    this->template validateAcyclicos<A3>(injector, ids);
    this->template validateAcyclicos<A4>(injector, ids);
    this->template validateAcyclicos<A5>(injector, ids);
    this->template validateAcyclicos<A6>(injector, ids);
    this->template validateAcyclicos<A7>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getDependency<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getDependency<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getDependency<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getDependency<A6>(injector));
    typename Key<A7>::Ptr a7(this->template getDependency<A7>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2, a3, a4, a5, a6, a7);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8>
struct NewBinding<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
    this->template validateAcyclicos<A3>(injector, ids);
    this->template validateAcyclicos<A4>(injector, ids);
    this->template validateAcyclicos<A5>(injector, ids);
    this->template validateAcyclicos<A6>(injector, ids);
    this->template validateAcyclicos<A7>(injector, ids);
    this->template validateAcyclicos<A8>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getDependency<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getDependency<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getDependency<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getDependency<A6>(injector));
    typename Key<A7>::Ptr a7(this->template getDependency<A7>(injector));
    typename Key<A8>::Ptr a8(this->template getDependency<A8>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9>
struct NewBinding<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9),
    Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
    this->template validateAcyclicos<A3>(injector, ids);
    this->template validateAcyclicos<A4>(injector, ids);
    this->template validateAcyclicos<A5>(injector, ids);
    this->template validateAcyclicos<A6>(injector, ids);
    this->template validateAcyclicos<A7>(injector, ids);
    this->template validateAcyclicos<A8>(injector, ids);
    this->template validateAcyclicos<A9>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getDependency<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getDependency<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getDependency<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getDependency<A6>(injector));
    typename Key<A7>::Ptr a7(this->template getDependency<A7>(injector));
    typename Key<A8>::Ptr a8(this->template getDependency<A8>(injector));
    typename Key<A9>::Ptr a9(this->template getDependency<A9>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9,
    typename A10>
struct NewBinding<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9,
    A10), Allocator>: public NakedBinding<Dependency, Scope> {
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;

  void validateAcyclic(sauce::shared_ptr<Injector> injector,
      TypeIds & ids) const {
    this->template validateAcyclicos<A1>(injector, ids);
    this->template validateAcyclicos<A2>(injector, ids);
    this->template validateAcyclicos<A3>(injector, ids);
    this->template validateAcyclicos<A4>(injector, ids);
    this->template validateAcyclicos<A5>(injector, ids);
    this->template validateAcyclicos<A6>(injector, ids);
    this->template validateAcyclicos<A7>(injector, ids);
    this->template validateAcyclicos<A8>(injector, ids);
    this->template validateAcyclicos<A9>(injector, ids);
    this->template validateAcyclicos<A10>(injector, ids);
  }

  Iface * provide(sauce::shared_ptr<Injector> injector) const {
    typename Key<A1>::Ptr a1(this->template getDependency<A1>(injector));
    typename Key<A2>::Ptr a2(this->template getDependency<A2>(injector));
    typename Key<A3>::Ptr a3(this->template getDependency<A3>(injector));
    typename Key<A4>::Ptr a4(this->template getDependency<A4>(injector));
    typename Key<A5>::Ptr a5(this->template getDependency<A5>(injector));
    typename Key<A6>::Ptr a6(this->template getDependency<A6>(injector));
    typename Key<A7>::Ptr a7(this->template getDependency<A7>(injector));
    typename Key<A8>::Ptr a8(this->template getDependency<A8>(injector));
    typename Key<A9>::Ptr a9(this->template getDependency<A9>(injector));
    typename Key<A10>::Ptr a10(this->template getDependency<A10>(injector));
    ImplAllocator allocator;
    Impl * impl = allocator.allocate(1);
    new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    return impl;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    ImplAllocator allocator;
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};

}
}

namespace i = ::sauce::internal;
namespace b = ::sauce::internal::bindings;

}

#endif // SAUCE_SAUCE_INTERNAL_BINDINGS_NEW_BINDING_H_
