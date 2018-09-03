// keyvi.go
package keyvi

// #cgo CFLAGS: -I../keyvi/include/keyvi/c_api/
// #cgo LDFLAGS: -lkeyvi_c -L ../build
// #include <stdlib.h>
// #include "c_api.h"
import "C"
import "unsafe"

type KeyviDictionary struct {
     d *C.struct_keyvi_dictionary;
}

func New()(KeyviDictionary) {
    cName := C.CString("../rust/test_data/fuzzy_non_ascii.kv")
    defer C.free(unsafe.Pointer(cName))
    var ret KeyviDictionary;
    ret.d = C.keyvi_create_dictionary(cName);
    return ret;
}

func (d KeyviDictionary)Free() {
    C.keyvi_dictionary_destroy(d.d);
}

func (d KeyviDictionary) Size() int {
    return int(C.keyvi_dictionary_get_size(d.d));
}
