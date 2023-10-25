//
// traits/bulk_execute_free.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2023 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_TRAITS_BULK_EXECUTE_FREE_HPP
#define BOOST_ASIO_TRAITS_BULK_EXECUTE_FREE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>
#include <boost/asio/detail/type_traits.hpp>

#if defined(BOOST_ASIO_HAS_WORKING_EXPRESSION_SFINAE)
# define BOOST_ASIO_HAS_DEDUCED_BULK_EXECUTE_FREE_TRAIT 1
#endif // defined(BOOST_ASIO_HAS_WORKING_EXPRESSION_SFINAE)

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace traits {

template <typename T, typename F, typename N, typename = void>
struct bulk_execute_free_default;

template <typename T, typename F, typename N, typename = void>
struct bulk_execute_free;

} // namespace traits
namespace detail {

struct no_bulk_execute_free
{
  static constexpr bool is_valid = false;
  static constexpr bool is_noexcept = false;
};

#if defined(BOOST_ASIO_HAS_DEDUCED_BULK_EXECUTE_FREE_TRAIT)

template <typename T, typename F, typename N, typename = void>
struct bulk_execute_free_trait : no_bulk_execute_free
{
};

template <typename T, typename F, typename N>
struct bulk_execute_free_trait<T, F, N,
  void_t<
    decltype(bulk_execute(declval<T>(), declval<F>(), declval<N>()))
  >>
{
  static constexpr bool is_valid = true;

  using result_type = decltype(
    bulk_execute(declval<T>(), declval<F>(), declval<N>()));

  static constexpr bool is_noexcept =
    noexcept(bulk_execute(declval<T>(), declval<F>(), declval<N>()));
};

#else // defined(BOOST_ASIO_HAS_DEDUCED_BULK_EXECUTE_FREE_TRAIT)

template <typename T, typename F, typename N, typename = void>
struct bulk_execute_free_trait :
  conditional_t<
    is_same<T, remove_reference_t<T>>::value
      && is_same<F, decay_t<F>>::value
      && is_same<N, decay_t<N>>::value,
    conditional_t<
      is_same<T, add_const_t<T>>::value,
      no_bulk_execute_free,
      traits::bulk_execute_free<add_const_t<T>, F, N>
    >,
    traits::bulk_execute_free<
      remove_reference_t<T>,
      decay_t<F>,
      decay_t<N>>
  >
{
};

#endif // defined(BOOST_ASIO_HAS_DEDUCED_BULK_EXECUTE_FREE_TRAIT)

} // namespace detail
namespace traits {

template <typename T, typename F, typename N, typename>
struct bulk_execute_free_default :
  detail::bulk_execute_free_trait<T, F, N>
{
};

template <typename T, typename F, typename N, typename>
struct bulk_execute_free :
  bulk_execute_free_default<T, F, N>
{
};

} // namespace traits
} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_TRAITS_BULK_EXECUTE_FREE_HPP
