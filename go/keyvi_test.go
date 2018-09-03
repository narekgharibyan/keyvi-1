// keyvi_test.go
package keyvi

import "testing"
import "fmt"


func TestKeyvi(t *testing.T) {
    d := New();
    fmt.Printf("%d\n", d.Size());
    d.Free();
}
