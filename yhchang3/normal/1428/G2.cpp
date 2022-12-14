#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;
ll f[6];
ll dp[1'000'001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	for(int i=0;i<6;i++)
		cin >> f[i];
	for(int i=0;i<=1'000'000;i++)
		dp[i] = - inf;
	dp[0] = 0;
	int w = 3;
	for(int i=0;i<6;i++, w *= 10){
		int c = 3 * (k - 1);
		ll v = f[i];
		for(int r=0;r<w;r++){
			deque<pair<int, ll> > dq;
			for(int j=0;j*w+r<=1'000'000;j++){
				int cur = j*w+r;
				while(!dq.empty() && j - dq[0].first > c)
					dq.pop_front();
				while(!dq.empty() && dp[cur] - j * v >= dq.back().second)
					dq.pop_back();
				dq.emplace_back(j, dp[cur] - j * v);
				dp[cur] = dq[0].second + j * v;
			}
		}
	}
	int base = 1;
	for(int i=0;i<6;i++, base *= 10){
		for(int w=1'000'000;w>=0;w--){
			for(int j=0;j<10 && w >= j * base;j++){
				ll v = 0;
				if(j == 3 || j == 6 || j == 9)
					v = f[i] * (j / 3);
				dp[w] = max(dp[w], dp[w - j * base] + v);	
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}