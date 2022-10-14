#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

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

pii relax(const pii &a, const pii &b) {
  if (a.first == b.first) return max(a, b);
  return min(a, b);
}
const int INF = 2e9 + 100;

int n;
vector<pii> ls;
vi kill;
vi price;

pii calc() {
  pii res;
  vi cnt(price.size());
  for (int i = 0; i < n; i++)
    cnt[kill[i]]++;

  int mi = INF, ma = -INF;
  for (int i = 0; i < price.size(); i++) {
    if (!cnt[i]) return mp(INF, -1);
    int cur = price[i] / cnt[i];
    mi = min(mi, cur);
    ma = max(ma, cur);
  }
  res.first = ma - mi;
  res.second = 0;

  for (int i = 0; i < ls.size(); i++) {
    if (kill[ls[i].first] == kill[ls[i].second])
      res.second++;
  }
  return res;
}

pii go(int i) {
  if (i == n) return calc();
  pii ans(INF, -1);
  for (kill[i] = 0; kill[i] < price.size(); kill[i]++)
    ans = relax(ans, go(i + 1));
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  map<string, int> ids;
  n = 0;
  ids["Anka"] = n++;
  ids["Chapay"] = n++;
  ids["Cleo"] = n++;
  ids["Troll"] = n++;
  ids["Dracul"] = n++;
  ids["Snowy"] = n++;
  ids["Hexadecimal"] = n++;

  int m;
  while (scanf("%d", &m) >= 1) {
    ls.clear();
    for (int i = 0; i < m; i++) {
      char b1[16], tmp[16], b2[16];
      scanf("%s%s%s", b1, tmp, b2);
      assert(!strcmp(tmp, "likes"));
      assert(ids.find(b1) != ids.end());
      assert(ids.find(b2) != ids.end());
      ls.pb(mp(ids[b1], ids[b2]));
    }
    price.resize(3);
    scanf("%d%d%d", &price[0], &price[1], &price[2]);
    kill = vi(n, -1);

    pii res = go(0);
    printf("%d %d\n", res.first, res.second);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}