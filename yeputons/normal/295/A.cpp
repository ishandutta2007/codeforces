#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

vll makeit(const vll &src) {
  assert(sz(src) >= 1);
  vll res(sz(src) - 1);
  ll c = 0;
  for (int i = 0; i < sz(src); i++) {
    c += src[i];
    if (i < sz(res))
      res[i] = c;
    else
      assert(c == 0);
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vector<pair<pii, int> > ops(m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &ops[i].first.first, &ops[i].first.second, &ops[i].second);
      ops[i].first.first--;
    }

    vector<ll> doo(m + 1, 0);
    for (int i = 0; i < k; i++) {
      int l, r;
      scanf("%d%d", &l, &r), l--;
      doo[l]++;
      doo[r]--;
    }
    doo = makeit(doo);

    vector<ll> add(n + 1, 0);
    for (int i = 0; i < n; i++) {
      add[i] += as[i];
      add[i + 1] -= as[i];
    }
    for (int i = 0; i < m; i++) {
      ll c = ll(ops[i].second) * doo[i];
      add[ops[i].first.first] += c;
      add[ops[i].first.second] -= c;
    }
    add = makeit(add);
    for (int i = 0; i < sz(add); i++)
      printf("%I64d%c", add[i], "\n "[i + 1 < sz(add)]);
  }
  return 0;
}