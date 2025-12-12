#include <node.h>

namespace crashme {

using v8::FunctionCallbackInfo;
using v8::Local;
using v8::Object;
using v8::Value;
using v8::Context;

void __attribute__((optimize("O0"))) Method(const FunctionCallbackInfo<Value>& args) {
  int *p = NULL;
  *p = 0x1337; // Dereferencing a NULL pointer
}

extern "C" NODE_MODULE_EXPORT void
NODE_MODULE_INITIALIZER(Local<Object> exports,
                        Local<Value> module,
                        Local<Context> context) {
  NODE_SET_METHOD(exports, "crashme", Method);
}

} // namespace crashme
