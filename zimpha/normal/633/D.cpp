#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10;
map<int, int> mp;
int v[MAXN], a[MAXN], n;
int L, R;

int gao(int f0, int f1) {
  mp[f0]--; mp[f1]--;
  int m = 2;
  v[0] = f0, v[1] = f1;
  for (; ;) {
    LL x = (LL)v[m - 1] + v[m - 2];
    if (x > R || x < L) break;
    if (mp.count(x) && mp[x]) {
      mp[x]--; v[m++] = x;
    } else break;
  }
  for (int i = 0; i < m; ++i) mp[v[i]]++;
  return m;
}

void run() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  L = *min_element(a, a + n);
  R = *max_element(a, a + n);
  for (int i = 0; i < n; ++i) mp[a[i]]++;
  int mx = 0;
  if (mp.count(0)) mx = mp[0];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) if (i != j) {
      if (a[i] == 0 && a[j] == 0) continue;
      mx = max(mx, gao(a[i], a[j]));
    }
  }
  printf("%d\n", mx);
}

int main() {
  run();
  return 0;
}