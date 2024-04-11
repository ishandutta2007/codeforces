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
const int mod = 1e9+7;

char a[16], b[16];
int n;
ll res = 0;

int dw(int x) {
  return x < n ? x : x - n;
}

void rec(int i) {
  if (i == n) {
    ++res;
    return;
  }
  for (int j = 0, j1 = i; j < n; ++j, j1 = dw(j1 + 1)) if (!a[j] && !b[j1]) {
    a[j] = b[j1] = 1;
    rec(i + 1);
    a[j] = b[j1] = 0;
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (0) for (n = 1; n <= 16; ++n) {
    res = 0;
    if (n % 2) {
      rec(0);        
    }
    for (int i = 1; i <= n; ++i) res = res % mod * i % mod;
    cout << res << ",";
  }
  vi x = {1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};
  int n;
  cin >> n;
  cout << x[n-1];
  cout << endl;
  return 0;
}