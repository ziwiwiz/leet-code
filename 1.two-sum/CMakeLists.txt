cmake_minimum_required(VERSION 3.0.0)
project(test_func VERSION 0.1.0)

enable_testing()
find_package(GTest REQUIRED)

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" DIR_TESTS)
add_executable(test_func ${DIR_TESTS})
target_link_libraries(test_func
  PRIVATE
    ${GTEST_BOTH_LIBRARIES}
    pthread
  )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(test_func
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
