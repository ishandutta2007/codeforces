
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

#define hash grtgnrtgn
typedef long long ll;
//typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

typedef unsigned long long hash;
const hash P = 29;

int n1, n2;
vvi chi2;
vector<hash> vhs1, vps1, vhs2;

typedef list<pair<hash, int> > HList;
const int HSZ = 1 << 16;
const int HMSK = HSZ - 1;
HList htbl[HSZ];

void addTbl(hash h) {
  int pos = h & HMSK;
  for (HList::iterator it = htbl[pos].begin(); it != htbl[pos].end(); it++)
    if (it->first == h) {
      it->second++;
      return;
    }
  htbl[pos].pb(mp(h, 1));
}
int getTbl(hash h) {
  int pos = h & HMSK;
  for (HList::iterator it = htbl[pos].begin(); it != htbl[pos].end(); it++)
    if (it->first == h)
      return it->second;
  return 0;
}

ll dfs2(int v, hash minu) {
  ll ans = getTbl(vhs2[v] - minu);
  for (int i = 0; i < sz(chi2[v]); i++)
    ans += dfs2(chi2[v][i], minu * P);
  return ans;
}

ll dfs(int v) {
  ll ans = 0;
  for (int i = 0; i < sz(chi2[v]); i++)
    ans += dfs(chi2[v][i]);
  ans += dfs2(v, vhs2[v]);
  return ans;
}

ll solve() {
  return dfs(0);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int ops;
  while (scanf("%d", &ops) >= 1) {
    vhs1 = vector<hash>(1, 0);
    vps1 = vector<hash>(1, 1);
    vhs2 = vector<hash>(1, 0);
    n1 = n2 = 1;

    for (int i = 0; i < HSZ; i++)
      htbl[i].clear();
    addTbl(0);

    chi2 = vvi(1);

    while (ops --> 0) {
      int t, v; char c;
      scanf(" %d%d %c", &t, &v, &c), v--;
      if (t == 1) {
        assert(v <= n1);
        vhs1.pb(vhs1[v] + vps1[v] * c);
        vps1.pb(vps1[v] * P);
        addTbl(vhs1[n1]);
        n1++;
      } else {
        assert(v <= n2);
        vhs2.pb(vhs2[v] * P + c);
        chi2[v].pb(n2);
        chi2.pb(vi());
        n2++;
      }
      printf("%I64d\n", solve());
    }
  }
  return 0;
}