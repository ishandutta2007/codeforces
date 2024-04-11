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
#define TASKNAME ""

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;


#define MAXID 1000
char buf[4096];

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  while (scanf("%s", buf) >= 1) {
    vb was(MAXID + 2, false);
    int cid = 0;
    for (int i = 0;; i++) {
      if (buf[i] < '0' || buf[i] > '9') {
        was[cid] = true;
        cid = 0;
      } else
        cid = cid * 10 + buf[i] - '0';
      if (!buf[i]) break;
    }

    int prevst = -1;
    bool first = true;
    for (int i = 0; i <= MAXID + 1; i++) {
      if (was[i]) {
        if (prevst < 0) {
          prevst = i;
        }
      } else
        if (prevst >= 0) {
          if (!first) printf(","); first = false;
          if (i - 1 == prevst) printf("%d", i - 1);
          else printf("%d-%d", prevst, i - 1);
          prevst = -1;
        }
    }
    printf("\n");
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}