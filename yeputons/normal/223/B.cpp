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

const int MAXL = 2e5 + 1e3;
char s[MAXL + 1];
char t[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s%s", s, t) >= 1) {
    int n = strlen(s);
    int m = strlen(t);

    vi maxPrefix(n, 0);
    {
      int ptr = 0;
      for (int i = 0; i < n; i++) {
        maxPrefix[i] = ptr;
        if (ptr < m && s[i] == t[ptr]) ptr++;
      }
    }
    vi maxSuffix(n, 0);
    {
      int ptr = m - 1;
      for (int i = n - 1; i >= 0; i--) {
        maxSuffix[i] = ptr + 1;
        if (ptr >= 0 && s[i] == t[ptr]) ptr--;
      }
    }

    vvi cnts(26, vi(m + 1, 0));
    for (int c = 0; c < 26; c++)
    for (int i = 0; i < m; i++)
      cnts[c][i + 1] = cnts[c][i] + (t[i] == 'a' + c);

    bool g = true;
    for (int i = 0; i < n; i++) {
      if (maxPrefix[i] + 1 < maxSuffix[i]) {
        g = false;
        break;
      }
      int l = max(0, maxSuffix[i] - 1);
      int r = min(m - 1, maxPrefix[i]);
      assert(l <= r);
      int c = s[i] - 'a';
      int cnt = cnts[c][r + 1] - cnts[c][l];
      if (!cnt) {
        g = false;
        break;
      }
    }
    printf(g ? "Yes\n" : "No\n");
  }
  return 0;
}