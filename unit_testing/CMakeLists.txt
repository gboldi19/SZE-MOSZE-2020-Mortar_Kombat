cmake_minimum_required(VERSION 2.6)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test 
# and the GTest and pthread library
add_library(Code_Lib ../JSONParser.cpp)
add_executable(json_unit_test json_parser_test.cpp)

target_link_libraries(json_unit_test ${GTEST_LIBRARIES} pthread Code_Lib)