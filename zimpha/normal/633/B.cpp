#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void run() {
  int m; cin >> m;
  vector<int> r;
  for (int i = 1; ; ++i) {
    int n = i, c = 0;
    for (int p = 5; p <= n; p *= 5) c += n / p;
    if (c == m) r.push_back(i);
    if (c > m) break;
  }
  printf("%d\n", (int)r.size());
  for (auto &x: r) printf("%d ", x);
  puts("");
}

int main() {
  run();
  return 0;
}