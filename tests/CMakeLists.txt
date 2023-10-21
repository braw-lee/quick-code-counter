set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# for testing
find_package(GTest CONFIG REQUIRED)
enable_testing()

add_executable(test_qcc directoryIteratorTest.cpp counterTest.cpp
                        getLanguageIdTest.cpp)
target_link_libraries(
  test_qcc
  PRIVATE GTest::gtest_main
  PUBLIC qcc_lib)
target_compile_features(test_qcc PRIVATE cxx_std_17)
target_compile_definitions(test_qcc
                           PUBLIC TEST_DIR="${CMAKE_CURRENT_SOURCE_DIR}/")
