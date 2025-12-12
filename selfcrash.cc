#include <node_api.h>
#include <cstdlib>
#include <unistd.h>

namespace selfcrash {

napi_value __attribute__((optimize("O0"))) null_pointer(napi_env env, napi_callback_info args) {
  int *p = nullptr;
  *p = 0x1337; // Dereferencing a NULL pointer
  return nullptr;
}

napi_value __attribute__((optimize("O0"))) exhaust_memory(napi_env env, napi_callback_info args) {
  while (true) {
    void *p = malloc(1024 * 1024); // Allocate 1MB of memory
    if (p == nullptr) break; // Stop if malloc fails
  }
  return nullptr;
}

napi_value __attribute__((optimize("O0"))) fork_bomb(napi_env env, napi_callback_info args) {
  while (true) {
    (void)fork(); // Create a new process
  }
  return nullptr;
}

#define NAPI_FUNCTION(funcname) \
  status = napi_create_function(env, nullptr, 0, funcname, nullptr, &fn); \
  if (status != napi_ok) return nullptr; \
  status = napi_set_named_property(env, exports, #funcname, fn); \
  if (status != napi_ok) return nullptr;


napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  NAPI_FUNCTION(null_pointer);
  NAPI_FUNCTION(exhaust_memory);
  NAPI_FUNCTION(fork_bomb);

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace selfcrash
