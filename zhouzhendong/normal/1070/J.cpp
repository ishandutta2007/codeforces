#include <bits/stdc++.h>
using namespace std;
const int N = 30010, K = 200010, INF = 0x3f3f3f3f;
int dp[N],num[30],n,m,k;
typedef long long ll;
char s[K];
void solve() {
  memset(num,0,sizeof num);
  scanf("%d%d%d",&n,&m,&k);
  scanf("%s",s+1);
  ll ans = 1ll << 60;
  for (int i = 1 ; i <= k ; ++ i)
    num[s[i] - 'A' + 1] ++;
  for (int s = 1 ; s <= 26 ; ++ s) {
    dp[0] = 0;
    for (int i = 1 ; i <= n ; ++ i)
      dp[i] = -INF;
    for (int i = 1 ; i <= 26 ; ++ i) {
      if (i == s) continue;
      for (int j = n ; j >= 0 ; -- j)
	dp[j] = min(m,max(dp[j] + num[i],dp[max(0,j - num[i])]));
    }
    for (int i = 0 ; i <= n ; ++ i) {
      if (n - i + m - dp[i] <= num[s]) {
	ans = min(ans,1ll * (n - i) * (m - dp[i]));
      }
    }
  }
  cout << ans << endl;
}
int main() {
  int T;
  scanf("%d",&T);
  while (T --)
    solve();
  return 0;
}