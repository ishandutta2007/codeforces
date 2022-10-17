#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 2010, inf = 1e9, mod = 998244353;
 

int n;
string s;
ll dp[N][N][2], cnt[N][N][2], was[N][N][2];
void calc(int l, int r, int k){
	if(was[l][r][k])
		return;
	was[l][r][k] = 1;  
	if(l > r){
		dp[l][r][k] = 0;
		cnt[l][r][k] = 1;
		return;
	}
	if(l == r){
		dp[l][r][k] = 0;
		if(k == 0)
			cnt[l][r][k] = 1 + (s[l] == '?');
		else
			cnt[l][r][k] = 1;
		return;
	}
	if(s[l] == '(' || s[l] == '?'){
		if(s[r] == '(' || s[r] == '?'){
			calc(l, r - 1, 1);                                           
			dp[l][r][k] = (dp[l][r][k] + dp[l][r - 1][1]) % mod;
    		cnt[l][r][k] = (cnt[l][r][k] + cnt[l][r - 1][1]) % mod;
		}
		if(s[r] == ')' || s[r] == '?'){
			calc(l + 1, r - 1, 0);
			dp[l][r][k] = (dp[l][r][k] + dp[l + 1][r - 1][0] + cnt[l + 1][r - 1][0]) % mod;
			cnt[l][r][k] = (cnt[l][r][k] + cnt[l + 1][r - 1][0]) % mod;
		}
	}
	if((s[l] == ')' || s[l] == '?') && k == 0){
		calc(l + 1, r, 0);                                           
		dp[l][r][k] = (dp[l][r][k] + dp[l + 1][r][0]) % mod;
    	cnt[l][r][k] = (cnt[l][r][k] + cnt[l + 1][r][0]) % mod;
	}
	//cerr << l << " " << r << " " << k << " " << dp[l][r][k] << " " << cnt[l][r][k] << endl;
}
int main(){
	cin >> s;
	n = s.size();
	calc(0, n - 1, 0);
	cout << dp[0][n - 1][0] << endl;
	return 0;
}