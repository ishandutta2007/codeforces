#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		vector<vector<int> > a(m, vector<int>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> a[j][i];
		sort(a.begin(), a.end(), [&](const vector<int>& A, const vector<int> &B){
			return *max_element(A.begin(), A.end()) > *max_element(B.begin(), B.end());
		});
		m = min(m, n);
		a.resize(m);
		int lim = 1 << n;
		vector<vector<int> > mx(m, vector<int>(lim));
		for(int mask=0;mask<lim;mask++){
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					int cur = 0;
					for(int k=0;k<n;k++)
						if((mask >> k) & 1) {
							int idx = j + k;
							if(j + k >= n)	idx -= n;
							cur += a[i][idx];
						}
					mx[i][mask] = max(mx[i][mask], cur);
				}
			}
		}
		vector<vector<int> > dp(m+1, vector<int>(lim));
		for(int i=1;i<=m;i++)
			for(int mask=0;mask<lim;mask++){
				dp[i][mask] = dp[i-1][mask];
				for(int sub=mask;sub;sub = (sub-1)&mask)
					dp[i][mask] = max(dp[i][mask], dp[i-1][mask^sub] + mx[i-1][sub]);
			}
		cout << dp[m][lim-1] << '\n';
	}
}