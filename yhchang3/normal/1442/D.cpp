#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a[3001];
ll ans = 0;

void solve(int l,int r,const vector<ll>& DP, int k){
	if(l == r){
		for(int i=0;i<a[l].size() && i <= k;i++)
			ans = max(ans, a[l][i] + DP[k - i]);
		return;
	}
	int mid = (l + r) >> 1;
	{
		vector<ll> dp(DP);
		for(int i=l;i<=mid;i++){
			int w = a[i].size() - 1;
			ll v = a[i].back();
			for(int j=k;j>=w;j--)
				dp[j] = max(dp[j], dp[j - w] + v);
		}
		solve(mid + 1, r, dp, k);
	}
	{
		vector<ll> dp(DP);
		for(int i=mid+1;i<=r;i++){
			int w = a[i].size() - 1;
			ll v = a[i].back();
			for(int j=k;j>=w;j--)
				dp[j] = max(dp[j], dp[j - w] + v);
		}
		solve(l, mid, dp, k);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		int sz;
		cin >> sz;
		a[i].resize(sz);
		for(auto &it:a[i])
			cin >> it;
		a[i].insert(a[i].begin(), 0);
		for(int j=1;j<a[i].size();j++)
			a[i][j] += a[i][j-1];
	}
	vector<ll> dp(k + 1);
	solve(1, n, dp, k);
	cout << ans << endl;
}