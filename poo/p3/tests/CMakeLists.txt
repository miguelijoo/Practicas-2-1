# GTest include code for fetch content over the internet 
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
# End GTest include code

# Testing persons library
add_executable(person-test person-test.cc)
target_link_libraries(person-test
 PRIVATE GTest::gtest_main person)
gtest_discover_tests(person-test)

# Testing catalog library
add_executable(catalog-test catalog-test.cc)
target_link_libraries(catalog-test
 PRIVATE GTest::gtest_main catalog)
gtest_discover_tests(catalog-test)

