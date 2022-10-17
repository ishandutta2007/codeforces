#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7,P=998244353;

int inv[N],d[N],s[N],n,m;

signed main()
{
	scanf("%lld%lld",&n,&m);
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=inv[P%i]*(P-P/i)%P;
	for(int i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)
		s[i]=(s[i-1]+d[i])%P;
	while(m--)
	{
		int a,b;
		scanf("%lld%lld",&a,&b);
		int x=lower_bound(d+1,d+n+1,b)-d;
		//x~n >=b 1~x-1
		int t=n-x+1;
		int ans=(s[x-1]*max(t+1-a,0ll)%P*inv[t+1]%P+(s[n]-s[x-1]+P)%P*max(t-a,0ll)%P*inv[t]%P)%P;
		printf("%lld\n",ans);
	}
}