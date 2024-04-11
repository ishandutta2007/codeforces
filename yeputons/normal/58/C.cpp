#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

#include <map>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    int a = 0, b = n - 1;
    for (; a <= b; a++, b--) {
      as[a] -= a;
      if (a != b)
        as[b] -= a;
    }
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[as[i]]++;
      eprintf("%d%c", as[i], "\n "[i + 1 < n]);
    }

    int ans = n;
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
      if (it->first > 0)
        ans = min(ans, n - it->second);
    printf("%d\n", ans);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}