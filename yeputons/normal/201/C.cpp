
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

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

const ll INFLL = 9e18;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n - 1);
    for (int i = 0; i + 1 < n; i++)
      scanf("%d", &as[i]);

    vector<vector<ll> > dyn(3, vll(n, 0));
    for (int step = 2; step >= 0; step--) {
      int needBe = (step == 1);

      for (int i = n - 1; i >= 0; i--) {
        if (step < 2)
          dyn[step][i] = dyn[step + 1][i];
        if (i >= n - 1) continue;

        int nes = as[i] - (as[i] % 2 != needBe);
        if (!nes) continue;
        dyn[step][i] = max(dyn[step][i], dyn[step][i + 1] + nes);
      }
    }
    printf("%I64d\n", *max_element(dyn[0].begin(), dyn[0].end()));
  }
  return 0;
}