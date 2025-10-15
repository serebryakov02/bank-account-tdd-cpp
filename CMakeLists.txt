cmake_minimum_required(VERSION 3.14)
project(BankAccountTDDCpp)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  bank-account-tdd-cpp
  tests/BankAccountTests.cpp
)

target_include_directories(
  bank-account-tdd-cpp
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  bank-account-tdd-cpp
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(bank-account-tdd-cpp)
