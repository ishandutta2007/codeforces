#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

bool mycmp(const pii &a, const pii &b) {
  return ll(a.first) * b.second < ll(b.first) * a.second;
}
bool mycmp2(const pii &a, const pii &b) {
  return ll(a.first) * b.second ==ll(b.first) * a.second;
}
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pii> pts;
    for (int i = 0; i < n; i++) {
      int k, b;
      scanf("%d%d", &k, &b);
      if (k > 0)
        pts.pb(mp(-b, k));
      if (k < 0)
        pts.pb(mp(b, -k));
    }
    sort(pts.begin(), pts.end(), mycmp);
    pts.erase(unique(pts.begin(), pts.end(), mycmp2), pts.end());
    printf("%d\n", sz(pts));
  }
  return 0;
}