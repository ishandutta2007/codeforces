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

const int MAXN = 99999;
const int MAXL = 5;
vector<vvi> ps(MAXL);

char nums[MAXN + 1][MAXL + 1];

int n, off;
vi fixed;

int calc(int y) {
  if (y >= n) return 1;

  for (int y2 = y + 1; y2 < n; y2++)
    fixed[y2] *= 10;
  
  int ans = 0;
  vi &curs = ps[off + y][fixed[y]];
  for (int i = 0; i < sz(curs); i++) {
    char *buf = nums[curs[i]] + off;

    for (int y2 = y + 1; y2 < n; y2++)
      fixed[y2] += buf[y2] - '0';
    ans += calc(y + 1);
    for (int y2 = y + 1; y2 < n; y2++)
      fixed[y2] -= buf[y2] - '0';
  }

  for (int y2 = y + 1; y2 < n; y2++)
    fixed[y2] /= 10;  
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (int i = 0; i <= MAXN; i++)
    snprintf(nums[i], sizeof nums[i], "%05d", i);

  {
    int cnt = 1;
    for (int i2 = 0; i2 < MAXL; i2++)
      ps[i2] = vvi(cnt), cnt *= 10;

    vb isp(MAXN + 1, true);
    for (int i = 2; i <= MAXN; i++) if (isp[i]) {
      for (int i2 = 2 * i; i2 <= MAXN; i2 += i)
        isp[i2] = false;

      char *buf = nums[i];
      int v = 0;
      for (int i2 = 0; i2 < MAXL; i2++) {
        ps[i2][v].pb(i);
        v = v * 10 + buf[i2] - '0';
      }
    }
  }

  int tc;
  assert(scanf("%d", &tc) >= 1);
  for (int tn = 0; tn < tc; tn++) {
    eprintf("%d/%d\n", tn, tc);
    int pst;
    scanf("%d", &pst);

    char tmp[6];
    snprintf(tmp, sizeof tmp, "%d", pst);
    n = strlen(tmp);
    off = MAXL - n;

    fixed = vi(n);
    fixed[0] = pst;
    for (int i = 1; i < n; i++)
      fixed[i] = tmp[i] - '0';

    printf("%d\n", calc(1));
  }
  return 0;
}