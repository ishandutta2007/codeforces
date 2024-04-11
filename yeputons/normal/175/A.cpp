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

const int MINV = 0;
const int MAXV = 1e6;
const int INF = 1e9;

char s[101];
bool valid(const string &s, int &val) {
  val = 0;
  for (int i = 0; i < s.length(); i++)
    val = val * 10 + (s[i] - '0');
  if (val < MINV || val > MAXV) return false;
  char buf[16];
  snprintf(buf, sizeof buf, "%d", val);
  return buf == s;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int l = strlen(s);
    vvi dyn(l + 1, vi(4, -INF));
    dyn[l][3] = 0;
    for (int i = l - 1; i >= 0; i--)
    for (int rem = 2; rem >= 0; rem--) {
      string cstr = "";
      for (int ne = i + 1; ne <= l; ne++) {
        cstr += s[ne - 1];
        int cur;
        if (!valid(cstr, cur)) continue;
        dyn[i][rem] = max(dyn[i][rem], cur + dyn[ne][rem + 1]);
      }
    }
    int ans = dyn[0][0];
    if (ans < 0) printf("-1\n");
    else printf("%d\n", ans);
  }
  return 0;
}