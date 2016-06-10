#include <emscripten.h>
#include "graph.hpp"

extern "C" {

// Not using size_t for array indices as the values used by the javascript code are signed.
void array_bounds_check(const int array_size, const int array_idx) {
  if (array_idx < 0 || array_idx >= array_size) {
    EM_ASM_INT({
      throw 'Array index ' + $0 + ' out of bounds: [0,' + $1 + ')';
    }, array_idx, array_size);
  }
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

// GraphMaker

GraphMaker* EMSCRIPTEN_KEEPALIVE emscripten_bind_GraphMaker_GraphMaker_0() {
  return new GraphMaker();
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_GraphMaker_makeGraph_0(GraphMaker* self) {
  self->makeGraph();
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_GraphMaker___destroy___0(GraphMaker* self) {
  delete self;
}

}
