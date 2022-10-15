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
const int mod = 1e9 + 7;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  if (s == string(n, '0')) {
    cout << n << endl;
    return 0;
  }
  int s0 = 0, s1 = n;
  while (s[s0] == '0') ++s0;
  while (s[s1 - 1] == '0') --s1;
  s = s.substr(s0, s1 - s0 - 1);
  s1 = n - s1;
  n = s.size();
  vl c(n + 1, 0);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    assert(s[i] == '1');
    int j = i + 1;
    while (j < n && s[j] == '0') ++j;
    int k = j - i;
    ll nsum = sum;
    for (int t = 0; t < k; ++t) {
      nsum = (nsum + sum + 1 - c[t]) % mod;
      c[t] = (sum + 1) % mod;
    }
    sum = nsum;
    i = j - 1;
  }
  cerr << sum << ' ' << s0 << ' ' << s1 << endl;
  cout << ((sum + 1) * (s0 + 1) % mod * (s1 + 1) % mod + mod) % mod << endl;
  return 0;
}