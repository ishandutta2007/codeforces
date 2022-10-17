#include <bits/stdc++.h> 
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> x(n);
    long long d = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      d = __gcd(d, x[i] - x[0]);
    } 
    cout << (((k - x[0]) % d == 0) ? "YES" : "NO") << endl;
  }
  return 0;
}