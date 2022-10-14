#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

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

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define sqr(a, b) ((a) * (a))
#define INF 2000000000
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef double dbl;
typedef vector<dbl> vdbl;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef pair<int, int> pii;

typedef vector<bool> vb;
typedef vector<string> vs;

int d(int x) {
  int sum = 0;
  for (; x; x /= 10) sum += x % 10;
  if (sum <= 9) return sum;
  else return d(sum);
}

int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vll cnt(10, 0);
    for (int i = 1; i <= n; i++)
      cnt[d(i)]++;

    vll cntRem = cnt;
    vvll cntMul(10, vll(10, 0));
    int mb = n;
    for (int a = 1; a <= n; a++) {
      while (a * mb > n) { cntRem[d(mb)]--; mb--; }

      int da = d(a);
      for (int i = 0; i < 10; i++)
        cntMul[da][i] += cntRem[i];
    }

    long long ans = 0;
    for (int a = 0; a < 10; a++) {
      if (!cnt[a]) continue;
      for (int b = 0; b < 10; b++) {
        if (!cnt[b]) continue;
        int dab = d(a * b);
        if (cnt[dab]) {
          assert(cntMul[a][b] <= cnt[a] * cnt[b]);
          ans += cnt[a] * cnt[b] * cnt[dab] - cntMul[a][b];
        }
      }
    }

    printf("%I64d\n", ans);

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}