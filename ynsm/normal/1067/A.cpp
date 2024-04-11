#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9, mod = 998244353, K = 200;
const ll INF = 1e18;

int n, a[N], dp[K + 1][2], nw[K + 1][2], pre[K + 1];
int get(int l, int r){
	if(l > r)
		return 0;
	int res = pre[r] - pre[l - 1];
	if(res < 0)
		res += mod;
	return res;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	if(a[1] == -1){
		for(int j = 1; j <= K; j++)
			dp[j][0] = 1;
	}else{
		dp[a[1]][0] = 1;
	}
	for(int i = 2; i <= n; i++){
		// 0                  
		pre[0] = 0;
		for(int j = 1; j <= K; j++){
			pre[j] = pre[j - 1] + dp[j][0];
			if(pre[j] >= mod)
				pre[j] -= mod;
		}
		for(int j = 1; j <= K; j++){
		    if(a[i] == -1 || a[i] == j){
		    	nw[j][0] += get(1, j - 1);
				nw[j][1] += get(j, j); 
			}
		}
		//1

		pre[0] = 0;
		for(int j = 1; j <= K; j++){
			pre[j] = pre[j - 1] + dp[j][1];
			if(pre[j] >= mod)
				pre[j] -= mod;
		}
		for(int j = 1; j <= K; j++){
			if(a[i] == -1 || a[i] == j){
			    nw[j][0] += get(1, j - 1);
				nw[j][1] += get(j, K); 
			}
		}
		for(int j = 1; j <= K; j++)
			for(int q = 0; q < 2; q++)
				dp[j][q] = nw[j][q] % mod, nw[j][q] = 0;	
	}

	ll ans = 0;
	for(int j = 1; j <= K; j++)
		ans += dp[j][1];
	cout << ans % mod;
	return 0;
}