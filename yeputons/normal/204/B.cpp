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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    map<int, int> c1;
    map<int, int> c2;

    vi acs;
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      c1[a]++;
      if (a != b) c2[b]++;
      acs.pb(a);
      acs.pb(b);
    }
    sort(acs.begin(), acs.end());
    acs.erase(unique(acs.begin(), acs.end()), acs.end());

    int needCnt = (n + 1) / 2;
    int ans = 1e9;
    for (int i = 0; i < sz(acs); i++) {
      int cc = acs[i];
      int ccnt = max(needCnt - c1[cc], 0);
      if (ccnt > c2[cc]) continue;
      ans = min(ans, ccnt);
    }
    printf("%d\n", ans <= 1e8 ? ans : -1);
  }
  return 0;
}