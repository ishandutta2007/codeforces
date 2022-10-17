#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;

#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)
#define mp1(a,b,c) P1(a,P(b,c))

int main(){
	static ll n,m,ta,tb,k;
	static ll a[200010],b[200010];
	scanf("%lld%lld%lld%lld%lld",&n,&m,&ta,&tb,&k);
	rep1(i,n)scanf("%lld",&a[i]);
	rep1(i,m)scanf("%lld",&b[i]);
	
	if(k+1 > m){
		cout << -1 << endl;
		return 0;
	}
	
	ll ret = b[k+1]+tb;
	rep1(i,n)a[i] += ta;
	static ll dp[200010];
	dp[0] = 0;
	rep1(i,m){
		dp[i] = dp[i-1];
		while(dp[i]+1 <= n && a[dp[i]+1] <= b[i])dp[i] ++;
		if(k < dp[i])break;
		if(i+1+k-dp[i] > m){
			ret = -1;
			break;
		}
		ret = max( ret , b[i+1+(k-dp[i])]+tb );
	}
	cout << ret << endl;
}