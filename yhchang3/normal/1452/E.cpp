#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int,int> > v(m);
	for(auto &[l, r]:v)
		cin >> l >> r;
	sort(v.begin(), v.end(), [&](const pair<int,int> &A, const pair<int,int> &B){
		return A.first + A.second < B.first + B.second;
	});
	vector<int> sum(m + 1);
	for(int i=1;i<=n-k+1;i++) {
		int cur = 0;
		for(int j=m-1;j>=0;j--)
			cur += max(0, min(v[j].second, i + k - 1) - max(v[j].first, i) + 1), sum[j] = max(cur, sum[j]);
	}
	int ans = 0;
	for(int i=1;i<=n-k+1;i++){
		int cur = 0;
		for(int j=0;j<m;j++)
			cur += max(0, min(v[j].second, i + k - 1) - max(v[j].first, i) + 1), ans = max(ans, cur + sum[j + 1]);
	}
	cout << ans << endl;
}