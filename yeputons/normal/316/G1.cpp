#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
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

int calcOccur(char *s, int l, char *t, int m) {
  vi pf(m, 0);
  for (int i = 1; i < m; i++) {
    int k = pf[i - 1];
    while (k && t[i] != t[k])
      k = pf[k - 1];
    if (t[i] == t[k]) k++;
    pf[i] = k;
  }

  int ans = 0;
  int pos = 0;
  for (int i = 0; i < l; i++) {
    while (pos && t[pos] != s[i])
      pos = pf[pos - 1];
    if (t[pos] == s[i]) pos++;

    if (pos == m) {
      ans++;
      pos = pf[pos - 1];
    }
  }
//  eprintf("calcOccur(%s, %d, %s, %d)=%d\n", s, l, t, m, ans);
  return ans;
}

const int MAXL = 60000;
const int MAXN = 20;

char s[MAXL + 1];
char ps[MAXN][MAXL + 1];
int pls[MAXN];
int lcs[MAXN], rcs[MAXN];

int lcps[MAXN][MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%s%d", s, &n) >= 1) {
    for (int i = 0; i < n; i++) {
      scanf("%s%d%d", ps[i], &lcs[i], &rcs[i]);
      pls[i] = strlen(ps[i]);
    }

    int l = strlen(s);

    int ans = 0;
    for (int len = 1; len <= l; len++) {
      vector<string> all;
      for (int st = 0; st + len <= l; st++) {
        bool g = true;
        for (int i = 0; i < n; i++) {
          int mycnt = calcOccur(ps[i], pls[i], s + st, len);
          g = g && lcs[i] <= mycnt && mycnt <= rcs[i];
        }
        if (g) {
//          eprintf("%s, %d\n", string(s + st, s + st + len).c_str(), len);
          all.pb(string(s + st, s + st + len));
        }
      }
      sort(all.begin(), all.end());
      ans += unique(all.begin(), all.end()) - all.begin();
    }
    printf("%d\n", ans);
  }
  return 0;
}