#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n; cin >> n;
  vector<int> a(n * n);
  for (int i = 0; i < n * n; ++ i) scanf("%d", &a[i]);
  sort(a.begin(), a.end(), greater<int>());
  vector<int> ret;
  multiset<int> S;
  for (int i = 0; i < n * n; ++ i) {
    auto it = S.find(a[i]);
    if (it != S.end()) S.erase(it);
    else {
      for (int x: ret) {
        int g = __gcd(x, a[i]);
        S.insert(g);
        S.insert(g);
      }
      ret.push_back(a[i]);
    }
  }
  for (auto &x: ret) cout << x << " "; cout << endl;
  return 0;
}