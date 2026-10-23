#include <iostream>

void takes_copy(int x);       // 1. Pass by Value
void takes_reference(int &x); // 2. Pass by Reference
void takes_pointer(int *x);   // 3. Pass by Pointer

int main() {
  int a = 10;
  int *b = &a; // 'b' is the address. '*b' is the value (10).

  // How to call them:
  takes_copy(*b);      // Give it the value (10)
  takes_reference(*b); // Give it the original object (10)
  takes_pointer(b);    // Give it the address (0x7ffee98b)
}
