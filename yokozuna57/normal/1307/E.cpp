#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int INF = 1000000000;
const ll MOD = 1000000007;

#define fr first
#define sc second

int main(){
	static int n,m;
	static int s[5005];
	static int f[5005],h[5005];
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d",&s[i]);
	}
	for(int i = 1 ; i <= m ; i ++){
		scanf("%d%d",&f[i],&h[i]);
	}
	
	static ll dp[5005];
	static ll ans[5005];
	for(int i = 0 ; i <= n ; i ++){
		dp[i] = 1;
		ans[i] = 0;
	}
	static ll cntl[5005],cntr[5005],imos[5005];
	for(int j = 1 ; j <= n ; j ++){
		for(int i = 0 ; i < 5005 ; i ++){
			cntl[i] = 0;
			cntr[i] = 0;
			imos[i] = 0;
		}
		for(int k = 1 ; k <= m ; k ++){
			if(f[k] != j)continue;
			int cnt = 0;
			int x=1;
			for( ; x <= n ; x ++){
				if(s[x] == j){
					cnt ++;
					if(cnt == h[k])break;
				}
			}
			if(x != n+1){
				cntl[x] ++;
			}
			cnt = 0;
			int y = n;
			for( ; y >= 1 ; y --){
				if(s[y] == j){
					cnt ++;
					if(cnt == h[k])break;
				}
			}
			if(y != 0){
				cntr[y] ++;
			}
			if(x < y){
				imos[x] ++;
				imos[y] --;
			}
		}
		for(int i = 0 ; i+1 < 5005 ; i ++){
			cntl[i+1] += cntl[i];
			imos[i+1] += imos[i];
		}
		for(int i = 5004 ; i-1 >= 0 ; i --){
			cntr[i-1] += cntr[i];
		}
		/*if(j == 2 || j == 3){
			for(int i = 0 ; i <= 5 ; i ++){
				cout << cntl[i] << " ";
			}
			cout << endl;
			for(int i = 0 ; i <= 5 ; i ++){
				cout << cntr[i] << " ";
			}
			cout << endl;
			for(int i = 0 ; i <= 5 ; i ++){
				cout << imos[i] << " ";
			}
			cout << endl;
		}*/
		for(int i = 0 ; i <= n ; i ++){
			if(i < n && s[i+1] == j){
				if(cntr[i+1] == cntr[i+2]){
					//puts("DEBUG");
					//cout << i << " " << j << endl;
					ans[i] = 0;
					dp[i] = 0;
					continue;
				}
				if(cntl[i] == 0 || (cntl[i] == 1 && cntr[i+1] == 1)){
					ans[i] ++;
				}
				else {
					ans[i] += 2;
					if(cntl[i] >= cntr[i+1]){
						dp[i] *= cntl[i]-1;
						dp[i] %= MOD;
					}
					else {
						dp[i] *= cntl[i];
						dp[i] %= MOD;
					}
				}
			}
			else {
				int cnt = 0;
				if(cntl[i] >= 1)cnt ++;
				if(cntr[i+1] >= 1)cnt ++;
				if(cnt == 1){
					ans[i] ++;
					dp[i] *= cntl[i]+cntr[i+1];
					dp[i] %= MOD;
				}
				else if(cnt == 2){
					if(cntl[i] == 1 && cntr[i+1] == 1){
						ans[i] ++;
						dp[i] *= 2;
						if(dp[i] >= MOD)dp[i] -= MOD;
					}
					else {
						ans[i] += 2;
						dp[i] *= cntl[i]*cntr[i+1]-imos[i];
						dp[i] %= MOD;
					}
				}
			}
		}
	}
	
	/*for(int i = 0 ; i <= n ; i ++){
		cout << ans[i] << " " << dp[i] << endl;
	}*/
	
	ll ret1=-1,ret2=0;
	for(int i = 0 ; i <= n ; i ++){
		if(ans[i] > ret1){
			ret1 = ans[i];
			ret2 = dp[i];
		}
		else if(ans[i] == ret1){
			ret2 += dp[i];
		}
	}
	cout << ret1 << " " << ret2%MOD << endl;
}