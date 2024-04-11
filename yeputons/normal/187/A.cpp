#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi p1(n), as(n);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x), x--;
      p1[x] = i;
    }

    vi p2(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &as[i]), as[i] = p1[as[i] - 1];
      p2[as[i]] = i;
    }

    int ans = n - 1;
    for (int i = 1; i < n; i++)
      if (p2[i - 1] < p2[i]) ans--;
      else break;
    printf("%d\n", ans);
  }
  return 0;
}