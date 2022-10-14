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

bool good(char c) {
  return
    (c == 'a') ||
    (c == 'e') ||
    (c == 'i') ||
    (c == 'o') ||
    (c == 'u') ||
    (c == 'y');
}

char buf[200];
int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  for (;;) {
    memset(buf, 0, sizeof buf);
    fgets(buf, sizeof buf, stdin);
    if (!strlen(buf)) break;

    char la = 0;
    for (int i = 0; buf[i]; i++) {
      if (buf[i] >= 'a' && buf[i] <= 'z') la = buf[i];
      if (buf[i] >= 'A' && buf[i] <= 'Z') la = buf[i] + 'a' - 'A';
    }
    printf(good(la) ? "YES\n" : "NO\n");
  }
  return 0;
}