#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int maxn = 5005;
int  dp[maxn][maxn];
int n,k;
int qpow(int a,int n)
{
    int ans=1;
    while(n > 0)
    {
        if( n & 1 ) ans = 1LL * ans * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
    }
    return ans;
}

void upd(int &a,int b){
	a += b;
	if(a >= mod) a -= mod;
}
int main()
{
	cin >> n >> k;
    dp[0][0] = 1;
    for(int i = 0;i <= k;++i)
    {
        for(int j=0;j<=k;++j)
        {
			upd(dp[i + 1][j],1LL * j * dp[i][j] % mod);
			upd(dp[i + 1][j + 1],1LL * (n - j + mod) * dp[i][j] % mod);
        }
    }
    int ans=0;
    for(int i=0;i<=k;++i){
		long long temp = 1;
		if(n - i < 0){
			temp = dp[k][i];
			temp = 1LL * qpow(qpow(2,i - n),mod - 2) * temp % mod;
		}else{
			temp = 1LL * dp[k][i] * qpow(2,n - i) % mod;
		}
		ans = (ans + temp) % mod;
	}
	cout << ans << endl;
	return 0;
}