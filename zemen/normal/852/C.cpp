#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

typedef complex<ld> pt;
const ld pi = acosl(-1);

ld s(pt a, pt b) {
  return fabsl(a.real() * b.imag() - a.imag() * b.real());
}

ld calc(int n, int a, int b) {
  pt A(1, 0);
  pt ang = polar(ld(1), pi / n);
  pt B = A * ang;
  pt C = B * ang;
  pt D = C * ang;
  pt E = (A * ld(n - a) + B * ld(a)) / ld(n);
  pt F = (C * ld(n - b) + D * ld(b)) / ld(n);
  ld s1 = s(F - E, C - E);
  ld s2 = s(F - E, B - E);
  return s1 - s2;
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  forn (i, n)
    cin >> a[i];
  vector<pair<ld, int>> res(n);
  forn (i, n) {
    ld k = calc(n, a[i], a[(i + 1) % n]);
    //cerr << i << ' ' << k << '\n';
    res[i] = {k, i};
  }
  sort(all(res));
  vector<int> p(n);
  forn (i, n)
    p[res[i].second] = i;
  forn (i, n)
    cout << p[i] << ' ';
  cout << '\n';
}