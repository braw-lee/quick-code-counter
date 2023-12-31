cmake_minimum_required(VERSION 3.22.1)
project(quick-code-counter LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABE qcc)
# set(CMAKE_CXX_CLANG_TIDY clang-tidy)

# for main executable
find_package(cxxopts CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
include_directories(include/qcc)
set(CPP_FILES
    src/main.cpp
    src/directoryIterator.cpp
    src/machine.cpp
    src/languageData.cpp
    src/fileInfo.cpp
    src/counter.cpp
    src/countInfo.cpp
    src/fileCountInfo.cpp
    src/lineInfo.cpp
    src/tableLanguageWise.cpp
    src/textFormatting.cpp
    src/tableVerbose.cpp
    src/languageWiseData.cpp
    src/jsonLanguageWise.cpp
    src/jsonVerbose.cpp
    src/csvLanguageWise.cpp
    src/csvVerbose.cpp
    src/chartHandler.cpp)

add_executable(${EXECUTABE} ${CPP_FILES})
add_library(${EXECUTABE}_lib STATIC ${CPP_FILES})
target_compile_features(${EXECUTABE} PRIVATE cxx_std_20)
target_link_libraries(${EXECUTABE} PUBLIC cxxopts::cxxopts)
target_link_libraries(${EXECUTABE} PRIVATE nlohmann_json::nlohmann_json)

target_compile_features(${EXECUTABE}_lib PRIVATE cxx_std_20)
target_link_libraries(${EXECUTABE}_lib PUBLIC cxxopts::cxxopts)
target_link_libraries(${EXECUTABE}_lib PUBLIC nlohmann_json::nlohmann_json)

target_include_directories(${EXECUTABE}
                           PRIVATE $(CMAKE_CURRENT_SOURCE_DIR)/include/qcc)
target_compile_definitions(${EXECUTABE}
                           PUBLIC PROJECT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/")
target_compile_definitions(${EXECUTABE}_lib
                           PUBLIC PROJECT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/")
add_subdirectory(tests)
