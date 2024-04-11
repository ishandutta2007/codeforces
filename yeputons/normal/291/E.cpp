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

const int MAXL = 3e5 + 100;
char buf[MAXL + 1];
int go[MAXL + 1][26];
int suf[MAXL + 1];
int l;

void calcGo() {
  l = strlen(buf);
  for (int i = 0; i <= l; i++) {
    memset(go[i], -1, sizeof go[i]);
    suf[i] = 0;
  }

  for (int i = 0; i < l; i++) {
    for (int ne = 0; ne < 26; ne++) {
      if (ne + 'a' == buf[i]) {
        go[i][ne] = i + 1;
     } else {
        if (i)
          go[i][ne] = go[suf[i]][ne];
        else
          go[i][ne] = 0;
      }
    }
    if (i > 0)
      suf[i + 1] = go[suf[i]][buf[i] - 'a'];
  }
}

vvi chi;
vector<vector<string> > chis;
int ans;

void dfs(int v, int spos) {
  for (int i = 0; i < sz(chi[v]); i++) {
    int pos = spos;
    const string &s = chis[v][i];
    for (int i2 = 0; s[i2]; i2++) {
      pos = go[pos][s[i2] - 'a'];
      if (pos == l)
        ans++, pos = suf[pos];
    }
    dfs(chi[v][i], pos);
  }
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    chi = vvi(n);
    chis = vector<vector<string> >(n);
    for (int i = 1; i < n; i++) {
      int p;
      scanf("%d%s", &p, buf), p--;
      chi[p].pb(i);
      chis[p].pb(buf);
    }

    scanf("%s", buf);
    ans = 0;
    calcGo();
    dfs(0, 0);
    printf("%d\n", ans);
  }
  return 0;
}