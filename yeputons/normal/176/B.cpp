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

const int MOD = 1e9 + 7;
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

const int MAXL = 1e3 + 10;
char a[MAXL + 1], b[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int k;
  while (scanf("%s%s%d", a, b, &k) >= 1) {
    int l = strlen(a);

    vb noffs(l);
    for (int off = 0; off < l; off++) {
      int pos = off;
      bool g = true;
      for (int i = 0; i < l; i++) {
        if (a[i] != b[pos]) g = false;
        if (++pos >= l) pos = 0;
      }
      if (!g) continue;
      noffs[off] = true;
    }

    vi ans(l);
    ans[0] = 1;
    for (int step = 0; step < k; step++) {
      int sum = 0;
      for (int i = 0; i < l; i++)
        add(sum, ans[i]);

      for (int i = 0; i < l; i++) {
        int cres = sum - ans[i];
        if (cres < 0) cres += MOD;
        ans[i] = cres;
      }
    }
    int res = 0;
    for (int i = 0; i < l; i++) if (noffs[i]) add(res, ans[i]);
    printf("%d\n", res);
  }
  return 0;
}