#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll xl = 1, xr, yl = 1, yr;
ll xc = -1, yc = -1;
bool rect = true;

mt19937 rr;
ll a, b;
ll n;

int random_ans(ll x, ll y) {
  if (a == x && b == y) {
    return 0;
  }
  vector<int> res;
  if (x < a) {
    res.push_back(1);
  }
  if (y < b) {
    res.push_back(2);
  }
  if (x > a || y > b) {
    res.push_back(3);
  }
  assert(!res.empty());
  return res[rr() % res.size()];
}

int qs = 0;
void ask(ll x, ll y) {
  ++qs;
  int res;
#ifdef LOCAL
  cout << x << ' ' << y << endl;
  res = random_ans(x, y);
  cerr << res << endl;
#else
  cout << x << ' ' << y << endl;
  cout.flush();
  cin >> res;
#endif
  if (res == 0) {
    cerr << "qs: " << qs << endl;
    exit(0);
  }
  if (res == 1) {
    xl = x + 1;
  }
  if (res == 2) {
    yl = y + 1;
  }
  if (res == 3) {
    xc = x, yc = y;
    rect = false;
  }
  if (!rect) {
    if (xc <= xl) {
      yr = yc - 1;
      rect = true;
    } else if (yc <= yl) {
      xr = xc - 1;
      rect = true;
    }
  }
}

void turn() {
  ll x, y;
  if (rect) {
    x = (xl + xr) / 2;
    y = (yl + yr) / 2;
  } else {
    if ((xc - xl + 1) * double(yr - yl + 1) > (yc - yl + 1) * double(xr - xl + 1)) {
      x = (xl + xc) / 2;
      y = yc;
    } else {
      x = xc;
      y = (yl + yc) / 2;
    }
  }
  assert(1 <= x && x <= n);
  assert(1 <= y && y <= n);
  ask(x, y);
}

signed main() {
#ifdef LOCAL
  ll seed = random_device{}();
  rr = mt19937(seed);
  ll n = rr() % ll(5) + 1;
  //ll n = rr() % ll(1e18) + 1;
  //a = rr() % n + 1;
  //b = rr() % n + 1;
  a = b = n;
  a = 1;
  cerr << "seed: " << n << '\n';
  cerr << "n: " << n << '\n';
  cerr << "secret: " << a << ' ' << b << '\n';
#else
  ll n;
  cin >> n;
#endif
  ::n = n;
  xr = yr = n;
  while (true) {
    turn();
  }
}