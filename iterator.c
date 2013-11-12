#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define T_SIZE 3
typedef struct {
  int a,b,c;
  const int size;
} T;

T newT(int a, int b, int c) {
  T t = {a,b,c,3};
  return t;
}

int** getIterator(T* t) {
  int** iter = malloc(sizeof(int*)*(t->size+1));
  int i=0;
  iter[i++] = &t->a;
  iter[i++] = &t->b;
  iter[i++] = &t->c;
  iter[i++] = NULL;
  return iter;
}

void deleteIterator(int** iter) {
  int i;
  for (i=0; i<T_SIZE; i++) {
    iter[i++] = NULL;
  }
  free(iter);
}
#undef T_SIZE

void test1() {
  T t = newT(1,2,3);

  int** iter = getIterator(&t);

  iter = getIterator(&t);
  assert(iter);
  assert(*(iter[0]) == t.a);
  assert(*(iter[1]) == t.b);
  assert(*(iter[2]) == t.c);

  t.a = 10;
  assert(*(iter[0]) == t.a);
  assert(*(iter[1]) == t.b);
  assert(*(iter[2]) == t.c);

  assert(iter[0] == &t.a);
  assert(iter[1] == &t.b);
  assert(iter[2] == &t.c);
  assert(iter[3] == NULL);

  deleteIterator(iter);
}

void test2() {
  T t = newT(1,2,3);
  int** iter = getIterator(&t);
  assert(iter);
  int i;
  for(i=0; i<t.size; i++) {
    int val = *(iter[i]);
    printf("%d ", val);
  }
  puts("");
  deleteIterator(iter);
}

void test3() {
  T t = newT(1,2,3);
  int** iter = getIterator(&t);
  int** orig = iter;
  assert(iter);
  for(; *iter !=NULL ; iter++) {
    int val = **iter;
    printf("%d ", val);
  }
  puts("");
  deleteIterator(orig);
}

int main() {

  test1();

  test2();
  test2();
  test2();
  test2();

  puts("");

  test3();
  test3();
  test3();
  test3();

  return 0;
}
