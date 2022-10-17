#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n, a[N];
bool f;

void dfs(int cur, int sum, int cnt) {
  if (cnt && !sum) {f = 1; return;}
  if (cur == n + 1) return;
  dfs(cur + 1, sum, cnt);
  dfs(cur + 1, sum + a[cur], cnt + 1);
  dfs(cur + 1, sum - a[cur], cnt + 1);
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]); 
  f = false; 
  dfs(1, 0, 0);
  puts(f ? "YES" : "NO");
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}