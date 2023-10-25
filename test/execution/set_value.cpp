//
// set_value.cpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2003-2023 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// Disable autolinking for unit tests.
#if !defined(BOOST_ALL_NO_LIB)
#define BOOST_ALL_NO_LIB 1
#endif // !defined(BOOST_ALL_NO_LIB)

// Test that header file is self-contained.
#include <boost/asio/execution/set_value.hpp>

#include <string>
#include "../unit_test.hpp"

#if !defined(BOOST_ASIO_NO_DEPRECATED)

namespace exec = boost::asio::execution;

static int call_count = 0;

struct no_set_value
{
};

struct const_member_set_value_0
{
  void set_value() const
  {
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <>
struct set_value_member<const const_member_set_value_0, void()>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

struct const_member_set_value_1
{
  template <typename V1>
  void set_value(V1&& v1) const
  {
    typename boost::asio::decay<V1>::type tmp(static_cast<V1&&>(v1));
    (void)tmp;
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename V1>
struct set_value_member<const const_member_set_value_1, void(V1)>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

struct const_member_set_value_2
{
  template <typename V1, typename V2>
  void set_value(V1&& v1, V2&& v2) const
  {
    typename boost::asio::decay<V1>::type tmp1(static_cast<V1&&>(v1));
    (void)tmp1;
    typename boost::asio::decay<V2>::type tmp2(static_cast<V2&&>(v2));
    (void)tmp2;
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename V1, typename V2>
struct set_value_member<const const_member_set_value_2, void(V1, V2)>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

struct free_set_value_const_receiver_0
{
  friend void set_value(const free_set_value_const_receiver_0&)
  {
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <>
struct set_value_free<const free_set_value_const_receiver_0, void()>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

struct free_set_value_const_receiver_1
{
  template <typename V1>
  friend void set_value(const free_set_value_const_receiver_1&,
      V1&& v1)
  {
    typename boost::asio::decay<V1>::type tmp(static_cast<V1&&>(v1));
    (void)tmp;
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename V1>
struct set_value_free<const free_set_value_const_receiver_1, void(V1)>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

struct free_set_value_const_receiver_2
{
  template <typename V1, typename V2>
  friend void set_value(const free_set_value_const_receiver_2&,
      V1&& v1, V2&& v2)
  {
    typename boost::asio::decay<V1>::type tmp1(static_cast<V1&&>(v1));
    (void)tmp1;
    typename boost::asio::decay<V2>::type tmp2(static_cast<V2&&>(v2));
    (void)tmp2;
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename V1, typename V2>
struct set_value_free<const free_set_value_const_receiver_2, void(V1, V2)>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

struct non_const_member_set_value_0
{
  void set_value()
  {
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <>
struct set_value_member<non_const_member_set_value_0, void()>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

struct non_const_member_set_value_1
{
  template <typename V1>
  void set_value(V1&& v1)
  {
    typename boost::asio::decay<V1>::type tmp(static_cast<V1&&>(v1));
    (void)tmp;
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename V1>
struct set_value_member<non_const_member_set_value_1, void(V1)>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

struct non_const_member_set_value_2
{
  template <typename V1, typename V2>
  void set_value(V1&& v1, V2&& v2)
  {
    typename boost::asio::decay<V1>::type tmp1(static_cast<V1&&>(v1));
    (void)tmp1;
    typename boost::asio::decay<V2>::type tmp2(static_cast<V2&&>(v2));
    (void)tmp2;
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename V1, typename V2>
struct set_value_member<non_const_member_set_value_2, void(V1, V2)>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_MEMBER_TRAIT)

struct free_set_value_non_const_receiver_0
{
  friend void set_value(free_set_value_non_const_receiver_0&)
  {
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <>
struct set_value_free<free_set_value_non_const_receiver_0, void()>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

struct free_set_value_non_const_receiver_1
{
  template <typename V1>
  friend void set_value(free_set_value_non_const_receiver_1&,
      V1&& v1)
  {
    typename boost::asio::decay<V1>::type tmp(static_cast<V1&&>(v1));
    (void)tmp;
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename V1>
struct set_value_free<free_set_value_non_const_receiver_1, void(V1)>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

struct free_set_value_non_const_receiver_2
{
  template <typename V1, typename V2>
  friend void set_value(free_set_value_non_const_receiver_2&,
      V1&& v1, V2&& v2)
  {
    typename boost::asio::decay<V1>::type tmp1(static_cast<V1&&>(v1));
    (void)tmp1;
    typename boost::asio::decay<V2>::type tmp2(static_cast<V2&&>(v2));
    (void)tmp2;
    ++call_count;
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename V1, typename V2>
struct set_value_free<free_set_value_non_const_receiver_2, void(V1, V2)>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef void result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_VALUE_FREE_TRAIT)

void test_can_set_value()
{
  constexpr bool b1 = exec::can_set_value<
      no_set_value&>::value;
  BOOST_ASIO_CHECK(b1 == false);

  constexpr bool b2 = exec::can_set_value<
      const no_set_value&>::value;
  BOOST_ASIO_CHECK(b2 == false);

  constexpr bool b3 = exec::can_set_value<
      no_set_value&, int>::value;
  BOOST_ASIO_CHECK(b3 == false);

  constexpr bool b4 = exec::can_set_value<
      const no_set_value&, int>::value;
  BOOST_ASIO_CHECK(b4 == false);

  constexpr bool b5 = exec::can_set_value<
      no_set_value&, int, std::string>::value;
  BOOST_ASIO_CHECK(b5 == false);

  constexpr bool b6 = exec::can_set_value<
      const no_set_value&, int, std::string>::value;
  BOOST_ASIO_CHECK(b6 == false);

  constexpr bool b7 = exec::can_set_value<
      const_member_set_value_0&>::value;
  BOOST_ASIO_CHECK(b7 == true);

  constexpr bool b8 = exec::can_set_value<
      const const_member_set_value_0&>::value;
  BOOST_ASIO_CHECK(b8 == true);

  constexpr bool b9 = exec::can_set_value<
      const_member_set_value_0&, int>::value;
  BOOST_ASIO_CHECK(b9 == false);

  constexpr bool b10 = exec::can_set_value<
      const const_member_set_value_0&, int>::value;
  BOOST_ASIO_CHECK(b10 == false);

  constexpr bool b11 = exec::can_set_value<
      const_member_set_value_0&, int, std::string>::value;
  BOOST_ASIO_CHECK(b11 == false);

  constexpr bool b12 = exec::can_set_value<
      const const_member_set_value_0&, int, std::string>::value;
  BOOST_ASIO_CHECK(b12 == false);

  constexpr bool b13 = exec::can_set_value<
      const_member_set_value_1&>::value;
  BOOST_ASIO_CHECK(b13 == false);

  constexpr bool b14 = exec::can_set_value<
      const const_member_set_value_1&>::value;
  BOOST_ASIO_CHECK(b14 == false);

  constexpr bool b15 = exec::can_set_value<
      const_member_set_value_1&, int>::value;
  BOOST_ASIO_CHECK(b15 == true);

  constexpr bool b16 = exec::can_set_value<
      const const_member_set_value_1&, int>::value;
  BOOST_ASIO_CHECK(b16 == true);

  constexpr bool b17 = exec::can_set_value<
      const_member_set_value_1&, int, std::string>::value;
  BOOST_ASIO_CHECK(b17 == false);

  constexpr bool b18 = exec::can_set_value<
      const const_member_set_value_1&, int, std::string>::value;
  BOOST_ASIO_CHECK(b18 == false);

  constexpr bool b19 = exec::can_set_value<
      const_member_set_value_2&>::value;
  BOOST_ASIO_CHECK(b19 == false);

  constexpr bool b20 = exec::can_set_value<
      const const_member_set_value_2&>::value;
  BOOST_ASIO_CHECK(b20 == false);

  constexpr bool b21 = exec::can_set_value<
      const_member_set_value_2&, int>::value;
  BOOST_ASIO_CHECK(b21 == false);

  constexpr bool b22 = exec::can_set_value<
      const const_member_set_value_2&, int>::value;
  BOOST_ASIO_CHECK(b22 == false);

  constexpr bool b23 = exec::can_set_value<
      const_member_set_value_2&, int, std::string>::value;
  BOOST_ASIO_CHECK(b23 == true);

  constexpr bool b24 = exec::can_set_value<
      const const_member_set_value_2&, int, std::string>::value;
  BOOST_ASIO_CHECK(b24 == true);

  constexpr bool b25 = exec::can_set_value<
      free_set_value_const_receiver_0&>::value;
  BOOST_ASIO_CHECK(b25 == true);

  constexpr bool b26 = exec::can_set_value<
      const free_set_value_const_receiver_0&>::value;
  BOOST_ASIO_CHECK(b26 == true);

  constexpr bool b27 = exec::can_set_value<
      free_set_value_const_receiver_0&, int>::value;
  BOOST_ASIO_CHECK(b27 == false);

  constexpr bool b28 = exec::can_set_value<
      const free_set_value_const_receiver_0&, int>::value;
  BOOST_ASIO_CHECK(b28 == false);

  constexpr bool b29 = exec::can_set_value<
      free_set_value_const_receiver_0&, int, std::string>::value;
  BOOST_ASIO_CHECK(b29 == false);

  constexpr bool b30 = exec::can_set_value<
      const free_set_value_const_receiver_0&, int, std::string>::value;
  BOOST_ASIO_CHECK(b30 == false);

  constexpr bool b31 = exec::can_set_value<
      free_set_value_const_receiver_1&>::value;
  BOOST_ASIO_CHECK(b31 == false);

  constexpr bool b32 = exec::can_set_value<
      const free_set_value_const_receiver_1&>::value;
  BOOST_ASIO_CHECK(b32 == false);

  constexpr bool b33 = exec::can_set_value<
      free_set_value_const_receiver_1&, int>::value;
  BOOST_ASIO_CHECK(b33 == true);

  constexpr bool b34 = exec::can_set_value<
      const free_set_value_const_receiver_1&, int>::value;
  BOOST_ASIO_CHECK(b34 == true);

  constexpr bool b35 = exec::can_set_value<
      free_set_value_const_receiver_1&, int, std::string>::value;
  BOOST_ASIO_CHECK(b35 == false);

  constexpr bool b36 = exec::can_set_value<
      const free_set_value_const_receiver_1&, int, std::string>::value;
  BOOST_ASIO_CHECK(b36 == false);

  constexpr bool b37 = exec::can_set_value<
      free_set_value_const_receiver_2&>::value;
  BOOST_ASIO_CHECK(b37 == false);

  constexpr bool b38 = exec::can_set_value<
      const free_set_value_const_receiver_2&>::value;
  BOOST_ASIO_CHECK(b38 == false);

  constexpr bool b39 = exec::can_set_value<
      free_set_value_const_receiver_2&, int>::value;
  BOOST_ASIO_CHECK(b39 == false);

  constexpr bool b40 = exec::can_set_value<
      const free_set_value_const_receiver_2&, int>::value;
  BOOST_ASIO_CHECK(b40 == false);

  constexpr bool b41 = exec::can_set_value<
      free_set_value_const_receiver_2&, int, std::string>::value;
  BOOST_ASIO_CHECK(b41 == true);

  constexpr bool b42 = exec::can_set_value<
      const free_set_value_const_receiver_2&, int, std::string>::value;
  BOOST_ASIO_CHECK(b42 == true);

  constexpr bool b43 = exec::can_set_value<
      non_const_member_set_value_0&>::value;
  BOOST_ASIO_CHECK(b43 == true);

  constexpr bool b44 = exec::can_set_value<
      const non_const_member_set_value_0&>::value;
  BOOST_ASIO_CHECK(b44 == false);

  constexpr bool b45 = exec::can_set_value<
      non_const_member_set_value_0&, int>::value;
  BOOST_ASIO_CHECK(b45 == false);

  constexpr bool b46 = exec::can_set_value<
      const non_const_member_set_value_0&, int>::value;
  BOOST_ASIO_CHECK(b46 == false);

  constexpr bool b47 = exec::can_set_value<
      non_const_member_set_value_0&, int, std::string>::value;
  BOOST_ASIO_CHECK(b47 == false);

  constexpr bool b48 = exec::can_set_value<
      const non_const_member_set_value_0&, int, std::string>::value;
  BOOST_ASIO_CHECK(b48 == false);

  constexpr bool b49 = exec::can_set_value<
      non_const_member_set_value_1&>::value;
  BOOST_ASIO_CHECK(b49 == false);

  constexpr bool b50 = exec::can_set_value<
      const non_const_member_set_value_1&>::value;
  BOOST_ASIO_CHECK(b50 == false);

  constexpr bool b51 = exec::can_set_value<
      non_const_member_set_value_1&, int>::value;
  BOOST_ASIO_CHECK(b51 == true);

  constexpr bool b52 = exec::can_set_value<
      const non_const_member_set_value_1&, int>::value;
  BOOST_ASIO_CHECK(b52 == false);

  constexpr bool b53 = exec::can_set_value<
      non_const_member_set_value_1&, int, std::string>::value;
  BOOST_ASIO_CHECK(b53 == false);

  constexpr bool b54 = exec::can_set_value<
      const non_const_member_set_value_1&, int, std::string>::value;
  BOOST_ASIO_CHECK(b54 == false);

  constexpr bool b55 = exec::can_set_value<
      non_const_member_set_value_2&>::value;
  BOOST_ASIO_CHECK(b55 == false);

  constexpr bool b56 = exec::can_set_value<
      const non_const_member_set_value_2&>::value;
  BOOST_ASIO_CHECK(b56 == false);

  constexpr bool b57 = exec::can_set_value<
      non_const_member_set_value_2&, int>::value;
  BOOST_ASIO_CHECK(b57 == false);

  constexpr bool b58 = exec::can_set_value<
      const non_const_member_set_value_2&, int>::value;
  BOOST_ASIO_CHECK(b58 == false);

  constexpr bool b59 = exec::can_set_value<
      non_const_member_set_value_2&, int, std::string>::value;
  BOOST_ASIO_CHECK(b59 == true);

  constexpr bool b60 = exec::can_set_value<
      const non_const_member_set_value_2&, int, std::string>::value;
  BOOST_ASIO_CHECK(b60 == false);

  constexpr bool b61 = exec::can_set_value<
      free_set_value_non_const_receiver_0&>::value;
  BOOST_ASIO_CHECK(b61 == true);

  constexpr bool b62 = exec::can_set_value<
      const free_set_value_non_const_receiver_0&>::value;
  BOOST_ASIO_CHECK(b62 == false);

  constexpr bool b63 = exec::can_set_value<
      free_set_value_non_const_receiver_0&, int>::value;
  BOOST_ASIO_CHECK(b63 == false);

  constexpr bool b64 = exec::can_set_value<
      const free_set_value_non_const_receiver_0&, int>::value;
  BOOST_ASIO_CHECK(b64 == false);

  constexpr bool b65 = exec::can_set_value<
      free_set_value_non_const_receiver_0&, int, std::string>::value;
  BOOST_ASIO_CHECK(b65 == false);

  constexpr bool b66 = exec::can_set_value<
      const free_set_value_non_const_receiver_0&, int, std::string>::value;
  BOOST_ASIO_CHECK(b66 == false);

  constexpr bool b67 = exec::can_set_value<
      free_set_value_non_const_receiver_1&>::value;
  BOOST_ASIO_CHECK(b67 == false);

  constexpr bool b68 = exec::can_set_value<
      const free_set_value_non_const_receiver_1&>::value;
  BOOST_ASIO_CHECK(b68 == false);

  constexpr bool b69 = exec::can_set_value<
      free_set_value_non_const_receiver_1&, int>::value;
  BOOST_ASIO_CHECK(b69 == true);

  constexpr bool b70 = exec::can_set_value<
      const free_set_value_non_const_receiver_1&, int>::value;
  BOOST_ASIO_CHECK(b70 == false);

  constexpr bool b71 = exec::can_set_value<
      free_set_value_non_const_receiver_1&, int, std::string>::value;
  BOOST_ASIO_CHECK(b71 == false);

  constexpr bool b72 = exec::can_set_value<
      const free_set_value_non_const_receiver_1&, int, std::string>::value;
  BOOST_ASIO_CHECK(b72 == false);

  constexpr bool b73 = exec::can_set_value<
      free_set_value_non_const_receiver_2&>::value;
  BOOST_ASIO_CHECK(b73 == false);

  constexpr bool b74 = exec::can_set_value<
      const free_set_value_non_const_receiver_2&>::value;
  BOOST_ASIO_CHECK(b74 == false);

  constexpr bool b75 = exec::can_set_value<
      free_set_value_non_const_receiver_2&, int>::value;
  BOOST_ASIO_CHECK(b75 == false);

  constexpr bool b76 = exec::can_set_value<
      const free_set_value_non_const_receiver_2&, int>::value;
  BOOST_ASIO_CHECK(b76 == false);

  constexpr bool b77 = exec::can_set_value<
      free_set_value_non_const_receiver_2&, int, std::string>::value;
  BOOST_ASIO_CHECK(b77 == true);

  constexpr bool b78 = exec::can_set_value<
      const free_set_value_non_const_receiver_2&, int, std::string>::value;
  BOOST_ASIO_CHECK(b78 == false);
}

void increment(int* count)
{
  ++(*count);
}

void test_set_value()
{
  call_count = 0;
  const_member_set_value_0 ex1 = {};
  exec::set_value(ex1);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  const const_member_set_value_0 ex2 = {};
  exec::set_value(ex2);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  exec::set_value(const_member_set_value_0());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  const_member_set_value_1 ex3 = {};
  exec::set_value(ex3, 123);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  const const_member_set_value_1 ex4 = {};
  exec::set_value(ex4, 123);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  exec::set_value(const_member_set_value_1(), 123);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  const_member_set_value_2 ex5 = {};
  exec::set_value(ex5, 123, std::string());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  const const_member_set_value_2 ex6 = {};
  exec::set_value(ex6, 123, std::string());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  exec::set_value(const_member_set_value_2(), 123, std::string());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  free_set_value_const_receiver_0 ex7 = {};
  exec::set_value(ex7);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  const free_set_value_const_receiver_0 ex8 = {};
  exec::set_value(ex8);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  exec::set_value(free_set_value_const_receiver_0());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  free_set_value_const_receiver_1 ex9 = {};
  exec::set_value(ex9, 123);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  const free_set_value_const_receiver_1 ex10 = {};
  exec::set_value(ex10, 123);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  exec::set_value(free_set_value_const_receiver_1(), 123);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  free_set_value_const_receiver_2 ex11 = {};
  exec::set_value(ex11, 123, std::string());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  const free_set_value_const_receiver_2 ex12 = {};
  exec::set_value(ex12, 123, std::string());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  exec::set_value(free_set_value_const_receiver_2(), 123, std::string());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  non_const_member_set_value_0 ex13 = {};
  exec::set_value(ex13);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  non_const_member_set_value_1 ex14 = {};
  exec::set_value(ex14, 123);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  non_const_member_set_value_2 ex15 = {};
  exec::set_value(ex15, 123, std::string());
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  free_set_value_non_const_receiver_0 ex16 = {};
  exec::set_value(ex16);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  free_set_value_non_const_receiver_1 ex17 = {};
  exec::set_value(ex17, 123);
  BOOST_ASIO_CHECK(call_count == 1);

  call_count = 0;
  free_set_value_non_const_receiver_2 ex18 = {};
  exec::set_value(ex18, 123, std::string());
  BOOST_ASIO_CHECK(call_count == 1);
}

BOOST_ASIO_TEST_SUITE
(
  "set_value",
  BOOST_ASIO_TEST_CASE(test_can_set_value)
  BOOST_ASIO_TEST_CASE(test_set_value)
)

#else // !defined(BOOST_ASIO_NO_DEPRECATED)

BOOST_ASIO_TEST_SUITE
(
  "set_value",
  BOOST_ASIO_TEST_CASE(null_test)
)

#endif // !defined(BOOST_ASIO_NO_DEPRECATED)
