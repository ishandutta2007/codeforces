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

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi t(n), f(n);
    vi as(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &as[i]);
      if (as[i] > 0) t[as[i] - 1]++;
      else f[-as[i] - 1]++;
    }

    int sf = 0;
    for (int i = 0; i < n; i++)
      sf += f[i];

    int kcnt = 0;
    vb ckill(n, false);
    for (int kill = 0; kill < n; kill++) {
      int ccnt = t[kill] + sf - f[kill];
      if (ccnt != m) continue;
      kcnt++;
      ckill[kill] = true;
    }
    assert(kcnt >= 1);

    for (int i = 0; i < n; i++) {
      int x = abs(as[i]) - 1;

      if (as[i] > 0) {
        if (!ckill[x]) printf("Lie\n");
        else if (kcnt == 1) printf("Truth\n");
        else printf("Not defined\n");
      } else {
        if (!ckill[x]) printf("Truth\n");
        else if (kcnt == 1) printf("Lie\n");
        else printf("Not defined\n");
      }
    }
  }
  return 0;
}