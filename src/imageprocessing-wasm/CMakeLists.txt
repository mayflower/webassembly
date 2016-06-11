cmake_minimum_required (VERSION 2.8)
project (BoostGilWasm LANGUAGES CXX)

set(CMAKE_EXECUTABLE_SUFFIX ".bc")

set(COMMON_CXX_FLAGS "-std=c++14 -Wall -Werror -Wno-c++11-narrowing -Wno-unused-local-typedef -pthread")
set(WASM_CXX_FLAGS "-s BINARYEN=1 -s \"BINARYEN_METHOD='native-wasm'\" -s DEMANGLE_SUPPORT=1")
set(EMSCRIPTEN_OUT_FLAGS "--post-js ${CMAKE_CURRENT_SOURCE_DIR}/glue.js --embed-file test.jpg --emrun")

# Set compile flags for emscripten clang
if(UNIX)
  set(CMAKE_CXX_FLAGS
    "$ENV{CXXFLAGS} ${COMMON_CXX_FLAGS} ${WASM_CXX_FLAGS}")
  set(CMAKE_CXX_FLAGS_RELEASE
    "$ENV{CXXFLAGS} -O3 -fomit-frame-pointer ${COMMON_CXX_FLAGS} ${WASM_CXX_FLAGS}")
  set(CMAKE_CXX_FLAGS_DEBUG
    "$ENV{CXXFLAGS} -Og -fno-omit-frame-pointer -g -ggdb ${COMMON_CXX_FLAGS} ${WASM_CXX_FLAGS}")
endif()

include_directories(
  "${JPEG_INCLUDE_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "/usr/local/include/")

add_executable(imageprocessing-wasm image.cpp glue.cpp)

#add_custom_target(
#  imageprocessing-wasm.html
#  "cp ${CMAKE_CURRENT_SOURCE_DIR}/test.jpg ${CMAKE_CURRENT_BINARY_DIR}/test.jpg && ${CMAKE_CXX_COMPILER} ${CMAKE_CURRENT_BINARY_DIR}/imageprocessing-wasm.bc ${JPEG_LIBRARY}/libjpeg.dylib -o ${CMAKE_CURRENT_BINARY_DIR}/imageprocessing-wasm.html -s BINARYEN=1 -s \"BINARYEN_METHOD='native-wasm'\" -s DEMANGLE_SUPPORT=1 ${EMSCRIPTEN_OUT_FLAGS}"
#  DEPENDS imageprocessing-wasm
#  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#  VERBATIM
#  USES_TERMINAL)
