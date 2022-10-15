#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

void f(const vi& bad, int& add, int& c) {
  ++add;
  c -= bad[add];
  
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, q;
    cin >> n >> q;
    vi a(n);
    int c = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] <= q) ++c;
    }
    /*if (q >= n) {
      cout << n << '\n';
      continue;
    }*/
    int x = 0;
    string res(n, '0');
//    bool fail = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] <= x) res[i] = '1';
      else if (x < q) {
        ++x;
        res[i] = '1';
      }
    }
    cout << res << '\n';
  }
  return 0;
}