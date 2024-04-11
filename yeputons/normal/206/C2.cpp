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
//typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

typedef unsigned long long hash;
const hash P = 29;

int n1, n2;
vvi chi2;
vi par2;
vector<hash> vhs1, vps1, vhs2;

typedef vector<pair<hash, int> > HList;
const int HSZ = 1 << 15;
const int HMSK = HSZ - 1;
HList htbl[2][HSZ];
int hver[2][HSZ];
int lhver[2];

void addTbl(int id, hash h, int k) {
  int pos = h & HMSK;
  if (hver[id][pos] < lhver[id]) {
    htbl[id][pos].clear();
    hver[id][pos] = lhver[id];
  }
  for (HList::iterator it = htbl[id][pos].begin(); it != htbl[id][pos].end(); it++)
    if (it->first == h) {
      it->second += k;
      return;
    }
  htbl[id][pos].pb(mp(h, k));
}
int getTbl(int id, hash h) {
  int pos = h & HMSK;
  if (hver[id][pos] < lhver[id]) {
    htbl[id][pos].clear();
    hver[id][pos] = lhver[id];
  }
  for (HList::iterator it = htbl[id][pos].begin(); it != htbl[id][pos].end(); it++)
    if (it->first == h)
      return it->second;
  return 0;
}

hash toFind, findK;
int dfs(int v) {
  hash curFind = toFind + vhs2[v] * findK;

  addTbl(1, curFind, 1);
  int res = 0;
  res += getTbl(1, vhs2[v]);
  for (int i = 0; i < sz(chi2[v]); i++)
    res += dfs(chi2[v][i]);
  addTbl(1, curFind, -1);
  return res;
}

int solve(hash h, hash k) {
  toFind = h;
  findK = k;
  lhver[1]++;
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
    par2 = vi(1, -1);
    n1 = n2 = 1;

    memset(hver, 0, sizeof hver);
    memset(lhver, 0, sizeof lhver);
    for (int i = 0; i < HSZ; i++) {
      htbl[0][i].clear();
      htbl[0][i].reserve(10);
    }
    for (int i = 0; i < HSZ; i++) {
      htbl[1][i].clear();
      htbl[1][i].reserve(10);
    }

    addTbl(0, 0, 1);

    long long cans = 1;

    chi2 = vvi(1);

    while (ops --> 0) {
      int t, v; char c;
      scanf(" %d%d %c", &t, &v, &c), v--;
      if (t == 1) {
        assert(v <= n1);
        vhs1.pb(vhs1[v] + vps1[v] * c);
        vps1.pb(vps1[v] * P);
        addTbl(0, vhs1[n1], 1);

        cans += solve(vhs1[n1], vps1[n1]);

        n1++;
      } else {
        assert(v <= n2);
        vhs2.pb(vhs2[v] * P + c);
        chi2[v].pb(n2);
        chi2.pb(vi());
        par2.pb(v);

        hash ck = 1;
        for (int x = n2; x >= 0; x = par2[x], ck *= P) {
          hash ch = vhs2[n2] - vhs2[x] * ck;
          cans += getTbl(0, ch);
        }
        n2++;
      }
      printf("%I64d\n", cans);
    }
  }
  return 0;
}