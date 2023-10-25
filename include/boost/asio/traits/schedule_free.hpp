//
// traits/schedule_free.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2023 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASIO_TRAITS_SCHEDULE_FREE_HPP
#define BOOST_ASIO_TRAITS_SCHEDULE_FREE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <boost/asio/detail/config.hpp>
#include <boost/asio/detail/type_traits.hpp>

#if defined(BOOST_ASIO_HAS_WORKING_EXPRESSION_SFINAE)
# define BOOST_ASIO_HAS_DEDUCED_SCHEDULE_FREE_TRAIT 1
#endif // defined(BOOST_ASIO_HAS_WORKING_EXPRESSION_SFINAE)

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace traits {

template <typename T, typename = void>
struct schedule_free_default;

template <typename T, typename = void>
struct schedule_free;

} // namespace traits
namespace detail {

struct no_schedule_free
{
  static constexpr bool is_valid = false;
  static constexpr bool is_noexcept = false;
};

#if defined(BOOST_ASIO_HAS_DEDUCED_SCHEDULE_FREE_TRAIT)

template <typename T, typename = void>
struct schedule_free_trait : no_schedule_free
{
};

template <typename T>
struct schedule_free_trait<T,
  void_t<
    decltype(schedule(declval<T>()))
  >>
{
  static constexpr bool is_valid = true;

  using result_type = decltype(schedule(declval<T>()));

  static constexpr bool is_noexcept = noexcept(schedule(declval<T>()));
};

#else // defined(BOOST_ASIO_HAS_DEDUCED_SCHEDULE_FREE_TRAIT)

template <typename T, typename = void>
struct schedule_free_trait :
  conditional_t<
    is_same<T, remove_reference_t<T>>::value,
    conditional_t<
      is_same<T, add_const_t<T>>::value,
      no_schedule_free,
      traits::schedule_free<add_const_t<T>>
    >,
    traits::schedule_free<remove_reference_t<T>>
  >
{
};

#endif // defined(BOOST_ASIO_HAS_DEDUCED_SCHEDULE_FREE_TRAIT)

} // namespace detail
namespace traits {

template <typename T, typename>
struct schedule_free_default :
  detail::schedule_free_trait<T>
{
};

template <typename T, typename>
struct schedule_free :
  schedule_free_default<T>
{
};

} // namespace traits
} // namespace asio
} // namespace boost

#include <boost/asio/detail/pop_options.hpp>

#endif // BOOST_ASIO_TRAITS_SCHEDULE_FREE_HPP
