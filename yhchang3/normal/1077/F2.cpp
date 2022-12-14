#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll INF = 8e18;

int a[5001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, x;
	cin >> n >> k >> x;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	vector<ll> dp(n+1, -INF);
	dp[0] = 0;
	for(int j=1;j<=x;j++){
		vector<ll> nxt(n+1, -INF);
		deque<int> dq;
		if(dp[0] != -INF)
			dq.emplace_back(0);
		for(int i=1;i<=n;i++){
			if(!dq.empty() && dq[0] < i - k)
				dq.pop_front();
			if(!dq.empty())
				nxt[i] = dp[dq[0]] + a[i];
			if(dp[i] != -INF){
				while(!dq.empty() && dp[dq.back()] <= dp[i])
					dq.pop_back();
				dq.emplace_back(i);
			}
		}
		dp.swap(nxt);
	}
	ll ans = -1;
	for(int i=n;i>n-k;i--)
		if(dp[i] != -INF)
			ans = max(ans, dp[i]);
	cout<<ans<<endl;
}