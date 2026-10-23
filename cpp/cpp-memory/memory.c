#include <malloc.h>
#include <stdio.h>

void usingMalloc() {
  int *p = (int *)malloc(sizeof(int));
  if (p == NULL) {
    puts("failed to allocate memory");
    return;
  }
  // *p = 5;
  printf("Value: %d\n", *p);
  printf("Heap Address (p): %p\n", (void *)p);
  printf("Stack Address (&p): %p\n", (void *)&p);
  // free(p);

  printf("Value after free: %d\n", *p);
  free(p);
}

int main() { usingMalloc(); }
