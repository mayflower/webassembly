cmake_minimum_required (VERSION 2.8)
project (BoostGraphWasm LANGUAGES CXX)

set(CMAKE_EXECUTABLE_SUFFIX ".html")
set(WASM_CXX_FLAGS "-s BINARYEN=1 -s \"BINARYEN_METHOD='native-wasm'\"")
set(WASM_POST_JS_FILE "--post-js ${PROJECT_SOURCE_DIR}/glue.js")
set(EMSCRIPTEN_RUN "--emrun")
set(EMSCRIPTEN_FLAGS "${WASM_CXX_FLAGS} ${WASM_POST_JS_FILE} ${EMSCRIPTEN_RUN}")

# Set compile flags for gcc and clang
if(UNIX)
  set(CMAKE_CXX_FLAGS
    "$ENV{CXXFLAGS} -std=c++14 -Wall -Werror -pthread ${EMSCRIPTEN_FLAGS}")
  set(CMAKE_CXX_FLAGS_RELEASE
    "$ENV{CXXFLAGS} -O3 -fomit-frame-pointer -std=c++14 -Wall -Werror -pthread ${EMSCRIPTEN_FLAGS}")
  set(CMAKE_CXX_FLAGS_DEBUG
    "$ENV{CXXFLAGS} -Og -fno-omit-frame-pointer -g -ggdb -std=c++14 -Wall -Werror -pthread ${EMSCRIPTEN_FLAGS}")
endif()

include_directories(
    "/usr/local/include"
  "${CMAKE_CURRENT_BINARY_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(page graph.cpp glue.cpp)
