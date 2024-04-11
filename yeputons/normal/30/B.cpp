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
typedef pair<int, int> pii;
typedef vector<bool> vb;

bool cmp(vi d1, vi d2) {
  for (int i = 2; i >= 0; i--) {
    if (d1[i] < d2[i]) return true;
    if (d1[i] > d2[i]) return false;
  }
  return true;
}

int dcnt[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool chk(vi d) {
  if (d[1] > 12) return false;

  int cdcnt = dcnt[d[1] - 1];
  if (!(d[2] % 4)) cdcnt++;
  if (d[0] > cdcnt) return false;
  return true; 
}

int scnt = 6;
int swp[] = { 0, 1, 0, 1, 0, 1 };

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  vi d1(3), d2(3);
  while (scanf("%d.%d.%d %d.%d.%d", &d1[0], &d1[1], &d1[2], &d2[0], &d2[1], &d2[2]) >= 6) {
    try {
      for (int s = 0; s < scnt; s++) {
        swap(d2[swp[s]], d2[swp[s] + 1]);
        if (!chk(d2)) continue;

        d2[2] += 18;
        if (cmp(d2, d1)) throw s;
        d2[2] -= 18;
      }
      printf("NO\n");
    } catch (...) {
      printf("YES\n");
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}