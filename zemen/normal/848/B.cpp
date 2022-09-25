#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

const int B = 1000100;

struct pt {
  int id, g, p, t;

  bool operator<(const pt& o) const {
    if (g != o.g)
      return g < o.g;
    if (g == 1) {
      return p > o.p;
    } else {
      return p < o.p;
    }
  }
};

bool cmp2(const pt& a, const pt& b) {
  if (a.g != b.g)
    return a.g > b.g;
  if (a.g == 1) {
    return a.p > b.p;
  } else {
    return a.p < b.p;
  }
}

vector<pt> a[B];
const int maxn = 100100;
int ax[maxn];
int ay[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, w, h;
  cin >> n >> w >> h;
  forn (i, n) {
    int g, p, t;
    cin >> g >> p >> t;
    a[p + maxn - t].push_back(pt{i, g, p, t});
  }
  forn (i, B) {
    if (a[i].empty())
      continue;
    sort(all(a[i]));
    auto b = a[i];
    sort(all(b), cmp2);
    //cerr << "group " << sz(a[i]) << '\n';
    forn (j, sz(a[i])) {
      int id = a[i][j].id;
      int p = b[j].p;
      int g = b[j].g;
      //cerr << id << ' ' << g << ' ' << p << '\n';
      if (g == 1) {
        ax[id] = p;
        ay[id] = h;
      } else {
        ax[id] = w;
        ay[id] = p;
      }
    }
  }
  forn (i, n) {
    cout << ax[i] << ' ' << ay[i] << '\n';
  }
}