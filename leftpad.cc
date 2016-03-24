// $ clang++ -std=c++11 -O3 leftpad.cc -o leftpad
// $ ./leftpad

#include <string.h>
#include <stdio.h>

namespace leftpad {
  enum Dirn {
    Left = 0,
    Right = 1,
  };

  // generic pad
  // either left or right padding
  // `src` and `ret` are NULL-terminated
  // callee must delete[] `ret`
  template<typename T, Dirn W> // W = Left or Right
  T* pad(T* src, int n, T ch = (T)' ') {
    const size_t c = strlen(src);
    const size_t p = W * (c*sizeof(T));
    const size_t sz = (c+n) * sizeof(T);
    T* ret = new T[sz];
    for(size_t i = p; i < p+n; i++) { // fill `ch`
      ret[i] = ch;
    }
    for(size_t i = (W^Dirn::Right)*n, j = 0;
        j < (c*sizeof(T));
        i++, j++) {
      ret[i] = src[j];
    }
    ret[sz] = 0;
    return ret;
  }

  void testPad() {
    const char* t = "Donald Trump 2016";

    char* g1 = pad<char, Dirn::Left>((char*)t, 3, ' ');
    const char* e1 = (char*)"   Donald Trump 2016";
    if(strcmp(e1, g1)) {
      printf("Fail!\nExpected \"%s\"; Got \"%s\"\n\n",
          e1, g1);
    } else {
      printf("Pass!\n");
    }
    delete[] g1;

    const char* e2 = (char*)"Donald Trump 2016   ";
    char* g2 = pad<char, Dirn::Right>((char*)t, 3, ' ');
    if(strcmp(e2, g2)) {
      printf("Fail!\nExpected \"%s\"; Got \"%s\"\n\n",
          e2, g2);
    } else {
      printf("Pass!\n");
    }
    delete[] g2;
  }
}

int main(int, char**) {
  leftpad::testPad();
  return 0;
}
