#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 200000 + 10;
int t[MAXN], d[MAXN], n, b;
LL ret[MAXN];

int main() {
  scanf("%d%d", &n, &b);
  LL cur = 0;
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &t[i], &d[i]);
    while (!Q.empty() && cur <= t[i]) {
      int x = Q.front(); Q.pop();
      ret[x] = cur + d[x];
      cur += d[x];
    }
    cur = max(cur, (LL)t[i]);
    if (cur == t[i] && Q.empty()) cur += d[i], ret[i] = cur;
    else if (Q.size() < b) Q.push(i);
    else ret[i] = -1;
  }
  while (!Q.empty()) {
    int x = Q.front(); Q.pop();
    ret[x] = cur + d[x]; cur += d[x];
  }
  for (int i = 0; i < n; ++i) printf("%lld ", ret[i]);
  puts("");
  return 0;
}