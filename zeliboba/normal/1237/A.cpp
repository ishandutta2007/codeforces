#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  int d = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] % 2 == 0) a[i] /= 2;
    else {
      a[i] = (a[i] + d) / 2;
      d *= -1;
    }
  }
  for (int i = 0; i < n; ++i) cout << a[i] << '\n';
  return 0;
}