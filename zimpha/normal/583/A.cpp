#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int va[100], vb[100];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n * n; ++ i) {
    int a, b; cin >> a >> b;
    if (!va[a] && !vb[b]) {
      va[a] = vb[b] = 1;
      cout << i + 1 << " ";
    }
  }
  cout << endl;
  return 0;
}