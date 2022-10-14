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

class Dsu {
  vi par, ss;

  public:
  int get(int x) {
    static int tmp[600];
    int tptr = 0;

    int v = x;
    for (; par[v] != v; v = par[v])
      tmp[tptr++] = v;
    for (int i = 0; i < tptr; i++)
      par[tmp[i]] = v;
    return v;
  }
  Dsu(int n = 0) : par(n), ss(n, 1) {
    for (int i = 0; i < n; i++)
      par[i] = i;
  }
  bool merge(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return false;
    if (ss[a] > ss[b]) swap(a, b);
    par[a] = b;
    ss[b] += ss[a];
    return true;
  }
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vector<pii> es(m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &es[i].first, &es[i].second);
      es[i].first--;
      es[i].second--;
    }

    vector<Dsu> dsu1(m + 1);
    dsu1[0] = Dsu(n);
    for (int i = 0; i < m; i++) {
      dsu1[i + 1] = dsu1[i];
      dsu1[i + 1].merge(es[i].first, es[i].second);
    }

    vector<Dsu> dsu2(m + 1);
    dsu2[m] = Dsu(n);
    for (int i = m - 1; i >= 0; i--) {
      dsu2[i] = dsu2[i + 1];
      dsu2[i].merge(es[i].first, es[i].second);
    }


    int k;
    scanf("%d", &k);
    while (k --> 0) {
      int l, r;
      scanf("%d%d", &l, &r), l--, r--;

      Dsu dsu(n);
      int ccnt = n;
      for (int i = 0; i < n; i++)
        ccnt -= dsu.merge(i, dsu1[l].get(i));
      for (int i = 0; i < n; i++)
        ccnt -= dsu.merge(i, dsu2[r + 1].get(i));
      printf("%d\n", ccnt);
    }
  }
  eprintf("%d\n", clock());
  return 0;
}