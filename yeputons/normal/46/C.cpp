#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int eprintf(const char *format, ...) {
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

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

char buf[2001];
int main() {
  int n;
  while (scanf("%d %s", &n, buf) >= 2) {
    for (int i = 0; i < n; i++) buf[i + n] = buf[i];
    buf[n + n - 1] = 0;
    
    int c1 = 0;
    for (int i = 0; i < n; i++) c1 += buf[i] == 'H';
    
    int bans = 1e9;
    for (int fih = 0; fih < n; fih++) {
      int cnt = 0;
      for (int i = 0; i < c1; i++)
        cnt += buf[fih + i] == 'T';
      bans = min(bans, cnt);
    }
    printf("%d\n", bans);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}