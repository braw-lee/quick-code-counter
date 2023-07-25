mkdir -p build
cmake -B build/ -S ./ --toolchain ../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build/
