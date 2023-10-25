//
// connect.cpp
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
#include <boost/asio/execution/connect.hpp>

#include <boost/system/error_code.hpp>
#include "../unit_test.hpp"

#if !defined(BOOST_ASIO_NO_DEPRECATED)

namespace exec = boost::asio::execution;

static int call_count = 0;

struct operation_state
{
  void start() noexcept
  {
  }
};

namespace boost {
namespace asio {
namespace traits {

#if !defined(BOOST_ASIO_HAS_DEDUCED_START_MEMBER_TRAIT)

template <>
struct start_member<operation_state>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = true;
  typedef void result_type;
};

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_START_MEMBER_TRAIT)

} // namespace traits
} // namespace asio
} // namespace boost

struct no_connect_1
{
};

struct no_connect_2 : exec::sender_base
{
};

struct no_connect_3
{
  template <typename R>
  operation_state connect(R&& r)
  {
    (void)r;
    return operation_state();
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename R>
struct connect_member<no_connect_3, R>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef operation_state result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_MEMBER_TRAIT)

struct const_member_connect : exec::sender_base
{
  const_member_connect()
  {
  }

  template <typename R>
  operation_state connect(R&& r) const
  {
    (void)r;
    ++call_count;
    return operation_state();
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename R>
struct connect_member<const const_member_connect, R>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef operation_state result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_MEMBER_TRAIT)

struct free_connect_const_receiver : exec::sender_base
{
  free_connect_const_receiver()
  {
  }

  template <typename R>
  friend operation_state connect(
      const free_connect_const_receiver&, R&& r)
  {
    (void)r;
    ++call_count;
    return operation_state();
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_FREE_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename R>
struct connect_free<const free_connect_const_receiver, R>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef operation_state result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_FREE_TRAIT)

struct non_const_member_connect : exec::sender_base
{
  template <typename R>
  operation_state connect(R&& r)
  {
    (void)r;
    ++call_count;
    return operation_state();
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_MEMBER_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename R>
struct connect_member<non_const_member_connect, R>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef operation_state result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_MEMBER_TRAIT)

struct free_connect_non_const_receiver : exec::sender_base
{
  free_connect_non_const_receiver()
  {
  }

  template <typename R>
  friend operation_state connect(
      free_connect_non_const_receiver&, R&& r)
  {
    (void)r;
    ++call_count;
    return operation_state();
  }
};

#if !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_FREE_TRAIT)

namespace boost {
namespace asio {
namespace traits {

template <typename R>
struct connect_free<free_connect_non_const_receiver, R>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = false;
  typedef operation_state result_type;
};

} // namespace traits
} // namespace asio
} // namespace boost

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_CONNECT_FREE_TRAIT)

struct receiver
{
  receiver()
  {
  }

  receiver(const receiver&)
  {
  }

  receiver(receiver&&) noexcept
  {
  }

  template <typename E>
  void set_error(E&& e) noexcept
  {
    (void)e;
  }

  void set_done() noexcept
  {
  }
};

namespace boost {
namespace asio {
namespace traits {

#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_ERROR_MEMBER_TRAIT)

template <typename E>
struct set_error_member<receiver, E>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = true;
  typedef void result_type;
};

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_ERROR_MEMBER_TRAIT)
#if !defined(BOOST_ASIO_HAS_DEDUCED_SET_DONE_MEMBER_TRAIT)

template <>
struct set_done_member<receiver>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = true;
  typedef void result_type;
};

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_DONE_MEMBER_TRAIT)

} // namespace traits
} // namespace asio
} // namespace boost

struct executor
{
  executor()
  {
  }

  executor(const executor&) noexcept
  {
  }

  executor(executor&&) noexcept
  {
  }

  template <typename F>
  void execute(F&& f) const noexcept
  {
    (void)f;
  }

  bool operator==(const executor&) const noexcept
  {
    return true;
  }

  bool operator!=(const executor&) const noexcept
  {
    return false;
  }
};

namespace boost {
namespace asio {
namespace traits {

#if !defined(BOOST_ASIO_HAS_DEDUCED_EXECUTE_MEMBER_TRAIT)

template <typename F>
struct execute_member<executor, F>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = true;
  typedef void result_type;
};

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_SET_ERROR_MEMBER_TRAIT)
#if !defined(BOOST_ASIO_HAS_DEDUCED_EQUALITY_COMPARABLE_TRAIT)

template <>
struct equality_comparable<executor>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = true;
};

#endif // !defined(BOOST_ASIO_HAS_DEDUCED_EQUALITY_COMPARABLE_TRAIT)

} // namespace traits
} // namespace asio
} // namespace boost

void test_can_connect()
{
  constexpr bool b1 = exec::can_connect<
      no_connect_1&, receiver>::value;
  BOOST_ASIO_CHECK(b1 == false);

  constexpr bool b2 = exec::can_connect<
      const no_connect_1&, receiver>::value;
  BOOST_ASIO_CHECK(b2 == false);

  constexpr bool b3 = exec::can_connect<
      no_connect_2&, receiver>::value;
  BOOST_ASIO_CHECK(b3 == false);

  constexpr bool b4 = exec::can_connect<
      const no_connect_2&, receiver>::value;
  BOOST_ASIO_CHECK(b4 == false);

  constexpr bool b5 = exec::can_connect<
      no_connect_3&, receiver>::value;
  BOOST_ASIO_CHECK(b5 == false);

  constexpr bool b6 = exec::can_connect<
      const no_connect_3&, receiver>::value;
  BOOST_ASIO_CHECK(b6 == false);

  constexpr bool b7 = exec::can_connect<
      const_member_connect&, receiver>::value;
  BOOST_ASIO_CHECK(b7 == true);

  constexpr bool b8 = exec::can_connect<
      const const_member_connect&, receiver>::value;
  BOOST_ASIO_CHECK(b8 == true);

  constexpr bool b9 = exec::can_connect<
      free_connect_const_receiver&, receiver>::value;
  BOOST_ASIO_CHECK(b9 == true);

  constexpr bool b10 = exec::can_connect<
      const free_connect_const_receiver&, receiver>::value;
  BOOST_ASIO_CHECK(b10 == true);

  constexpr bool b11 = exec::can_connect<
      non_const_member_connect&, receiver>::value;
  BOOST_ASIO_CHECK(b11 == true);

  constexpr bool b12 = exec::can_connect<
      const non_const_member_connect&, receiver>::value;
  BOOST_ASIO_CHECK(b12 == false);

  constexpr bool b13 = exec::can_connect<
      free_connect_non_const_receiver&, receiver>::value;
  BOOST_ASIO_CHECK(b13 == true);

  constexpr bool b14 = exec::can_connect<
      const free_connect_non_const_receiver&, receiver>::value;
  BOOST_ASIO_CHECK(b14 == false);

  constexpr bool b15 = exec::can_connect<
      executor&, receiver>::value;
  BOOST_ASIO_CHECK(b15 == true);

  constexpr bool b16 = exec::can_connect<
      const executor&, receiver>::value;
  BOOST_ASIO_CHECK(b16 == true);
}

void increment(int* count)
{
  ++(*count);
}

void test_connect()
{
  receiver r;

  call_count = 0;
  const_member_connect s1;
  operation_state o1 = exec::connect(s1, r);
  BOOST_ASIO_CHECK(call_count == 1);
  (void)o1;

  call_count = 0;
  const const_member_connect s2;
  operation_state o2 = exec::connect(s2, r);
  BOOST_ASIO_CHECK(call_count == 1);
  (void)o2;

  call_count = 0;
  operation_state o3 = exec::connect(const_member_connect(), r);
  BOOST_ASIO_CHECK(call_count == 1);
  (void)o3;

  call_count = 0;
  free_connect_const_receiver s3;
  operation_state o4 = exec::connect(s3, r);
  BOOST_ASIO_CHECK(call_count == 1);
  (void)o4;

  call_count = 0;
  const free_connect_const_receiver s4;
  operation_state o5 = exec::connect(s4, r);
  BOOST_ASIO_CHECK(call_count == 1);
  (void)o5;

  call_count = 0;
  operation_state o6 = exec::connect(free_connect_const_receiver(), r);
  BOOST_ASIO_CHECK(call_count == 1);
  (void)o6;

  call_count = 0;
  non_const_member_connect s5;
  operation_state o7 = exec::connect(s5, r);
  BOOST_ASIO_CHECK(call_count == 1);
  (void)o7;

  call_count = 0;
  free_connect_non_const_receiver s6;
  operation_state o8 = exec::connect(s6, r);
  BOOST_ASIO_CHECK(call_count == 1);
  (void)o8;

  executor s7;
  exec::connect_result<executor&,
      receiver&>::type o9 = exec::connect(s7, r);
  BOOST_ASIO_CHECK((
      exec::is_operation_state<
        exec::connect_result<executor&, receiver&>::type
      >::value));
  (void)o9;

  const executor s8;
  exec::connect_result<const executor&,
      receiver&>::type o10 = exec::connect(s8, r);
  (void)exec::connect(s8, r);
  BOOST_ASIO_CHECK((
      exec::is_operation_state<
        exec::connect_result<const executor&, receiver&>::type
      >::value));
  (void)o10;
}

BOOST_ASIO_TEST_SUITE
(
  "connect",
  BOOST_ASIO_TEST_CASE(test_can_connect)
  BOOST_ASIO_TEST_CASE(test_connect)
)

#else // !defined(BOOST_ASIO_NO_DEPRECATED)

BOOST_ASIO_TEST_SUITE
(
  "connect",
  BOOST_ASIO_TEST_CASE(null_test)
)

#endif // !defined(BOOST_ASIO_NO_DEPRECATED)
