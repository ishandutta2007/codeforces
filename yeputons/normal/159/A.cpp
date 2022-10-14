#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
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

template<typename T> pair<T, T> swap(const pair<T, T> &a) { return mp(a.second, a.first); }

char buf1[101];
char buf2[101];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, d;
  while (scanf("%d%d", &n, &d) >= 1) {
    set<pair<string, string> > ans;
    vector<pair<pair<string, string>, int> > evs;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%s%s%d", buf1, buf2, &t);
      evs.pb(mp(mp(buf1, buf2), t));
    }

    for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++) if (evs[a].first == swap(evs[b].first) && abs(evs[a].second - evs[b].second) <= d && evs[a].second != evs[b].second) {
      pair<string, string> res = evs[a].first;
      if (res.second < res.first) swap(res.first, res.second);
      ans.insert(res);
    }
    printf("%d\n", sz(ans));
    for (set<pair<string, string> >::iterator it = ans.begin(); it != ans.end(); it++)
      printf("%s %s\n", it->first.c_str(), it->second.c_str());
  }
  return 0;
}