#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>

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

template<typename T> void printv(const char* name, const char* fmt, vector<T> v) {
  #ifdef DEBUG
  eprintf("%s:", name);
  for (unsigned int i = 0; i < v.size(); i++) {
    eprintf(" ");
    eprintf(fmt, v[i]);
  }
  eprintf("\n");
  #endif
}
void printv(const char* name, const char* fmt, vector<bool> v) {
  #ifdef DEBUG
  eprintf("%s:", name);
  for (unsigned int i = 0; i < v.size(); i++) {
    eprintf(" ");
    eprintf(fmt, !!v[i]);
  }
  eprintf("\n");
  #endif
}

#define min(a, b) (((a) < (b)) ? (a) : (b)) 
#define max(a, b) (((a) > (b)) ? (a) : (b)) 
#define sqr(a) ((a) * (a))
#define INF 2000000000
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef double dbl;
typedef vector<dbl> vd;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef vector<string> vs;

char total[100001];
char as[101], bs[101];
int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  while (scanf(" %s %s %s", total, as, bs) >= 3) {
    int n = strlen(total);
    int al = strlen(as), bl = strlen(bs);

    int ANS = 0;
    for (int STEP = 0; STEP < 2; STEP++) {
      int start = n;
      for (int i = 0; i + al <= n; i++) {
        bool good = true;
        for (int i2 = 0; i2 < al; i2++)
          if (total[i + i2] != as[i2]) { good = false; break; }
        if (good) { start = i + al; break; }
      }

      int start2 = n + 1;
      for (int i = start; i + bl <= n; i++) {
        bool good = true;
        for (int i2 = 0; i2 < bl; i2++)
          if (total[i + i2] != bs[i2]) { good = false; break; }
        if (good) { start2 = i + bl; break; }
      }
      if (start2 <= n) ANS |= 1 << STEP;

      int l = 0, r = n - 1;
      for (; l < r; l++, r--)
        swap(total[l], total[r]);    
    }
    switch (ANS) {
    case 0: printf("fantasy\n"); break;
    case 1: printf("forward\n"); break;
    case 2: printf("backward\n"); break;
    case 3: printf("both\n"); break;
    }

    #ifndef DEBUG
    break;
    #endif
  }

  return 0;
}