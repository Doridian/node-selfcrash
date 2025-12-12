#include <node_api.h>

namespace crashme {

napi_value __attribute__((optimize("O0"))) Method(napi_env env, napi_callback_info args) {
  int *p = NULL;
  *p = 0x1337; // Dereferencing a NULL pointer
  return nullptr;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "crashme", fn);
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace crashme
