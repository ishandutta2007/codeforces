#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n; scanf("%d", &n);
  vector<int> v;
  for (int i = 1; i <= n; ++ i) {
    int s = 1;
    while (!v.empty() && v.back() == s) {
      v.pop_back();
      s ++;
    }
    v.push_back(s);
  }
  for (auto &x: v) cout << x << " ";
  cout << endl;
  return 0;
}