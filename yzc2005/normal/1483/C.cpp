#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 3e5 + 5;
int n, h[N], b[N];
int stk[N], top;
ll dp[N], val[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &h[i]); 
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  multiset<ll> dps;
  for (int i = 1; i <= n; ++i) {
    ll cur = dp[i - 1];
    while (top && h[i] < h[stk[top]]) {
      dps.erase(dps.find(val[top] + b[stk[top]]));
      cur = max(cur, val[top]);
      --top;
    }    
    stk[++top] = i;
    val[top] = cur;
    dps.insert(cur + b[i]);
    dp[i] = *--dps.end();
  }
  printf("%lld\n", dp[n]);
  return 0;
}