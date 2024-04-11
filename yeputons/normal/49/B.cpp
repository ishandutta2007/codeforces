#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int eprintf(const char* format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> pii;

typedef vector<bool> vb;

char s1[100];
char s2[100];
char res[100];

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  int a, b;
  while (scanf("%d%d", &a, &b) >= 2) {
    memset(s1, 0, sizeof s1);
    memset(s2, 0, sizeof s2);
    int l1 = 0, l2 = 0;
    for (; a; a /= 10) s1[l1++] = (a % 10);
    for (; b; b /= 10) s2[l2++] = (b % 10);

    int base = 0;
    for (int i = 0; i < 100; i++) base = max(base, max(s1[i], s2[i]) + 1);
    assert(base >= 2);
   
    int c = 0;
    int l = 0;
    for (int i = 0; i < 100; i++) {
      c += s1[i] + s2[i];
      res[i] = c % base;
      if (c) l = i + 1;
      c /= base;
    }
    printf("%d\n", l);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}