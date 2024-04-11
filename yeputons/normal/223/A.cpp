#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

const int MAXL = 1e5 + 1e3;
char s[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int n = strlen(s);
    vi cnts(n + 1, 0);
    for (int i = 0; i < n; i++)
      cnts[i + 1] = cnts[i] + (s[i] == '[');

    vector<pair<char, int> > cst;

    int ans = 0;
    int al = 0, ar = 0;

    int lst = 0;
    for (int i = 0; s[i]; i++) {
      switch (s[i]) {
      case '(': cst.pb(mp(')', i)); break;
      case '[': cst.pb(mp(']', i)); break;
      default:
        if (cst.empty() || cst.back().first != s[i]) {
          lst = i + 1;
          cst.clear();
        } else
          cst.pop_back();
        break;
      }
      if (i < lst) continue;
      int cl = cst.empty() ? lst : cst.back().second + 1;
      int cr = i + 1;
      assert(cl <= cr);
      assert(0 <= cl && cr <= n);
      int ccnt = cnts[cr] - cnts[cl];
      if (ccnt > ans) {
        ans = ccnt;
        al = cl;
        ar = cr;
      }
    }
    printf("%d\n", ans);
    printf("%s\n", string(s, al, ar - al).c_str());
  }
  return 0;
}