#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

const int MAXV = 2011;
const int INF = 1e9;

bool good(int a, int b) {
  if (a < 1000 || b < 1000) return false;
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    if (a % 10 != b % 10) cnt++;
    a /= 10, b /= 10;
  }
  return cnt <= 1;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++) scanf("%d", &as[i]);
    try {
      vi minv(n + 1, INF);
      minv[0] = 1000;
      for (int i = 0; i < n; i++) {
        for (int nv = minv[i]; nv <= MAXV; nv++)
          if (good(nv, as[i])) {
            minv[i + 1] = nv;
            break;
          }
      }
      if (minv[n] >= INF) throw 0;
      for (int i = 1; i <= n; i++)
        printf("%d\n", minv[i]);
    } catch (...) {
      printf("No solution\n");
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}