#include<bits/stdc++.h>
using namespace std;
const int N=100010,V=100010,mod=1000000007;
int n,v=100000,a[N]={};
vector<int> fac[V];
inline long long power(long long x,long long y)
{
	long long t=1;
	for(; y; x=x*x%mod,y>>=1)
		if(y&1) t=t*x%mod;
	return t;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=v;++i)
		for(int j=i;j<=v;j+=i)
			fac[j].push_back(i);
}
void work()
{
	long long ans=0;
	for(int t=1;t<=v;++t)
	{
		for(int i=0;i<(int)fac[t].size();++i)
			fac[t][i]=lower_bound(a+1,a+n+1,fac[t][i])-a;
		fac[t].push_back(n+1);
		for(int i=0;i<(int)fac[t].size()-1;++i)
			fac[t][i]=fac[t][i+1]-fac[t][i];
		fac[t].pop_back();
		long long s=(power(fac[t].size(),fac[t].back())
					+mod-power(fac[t].size()-1,fac[t].back()))%mod;
		for(int i=0;i<(int)fac[t].size()-1;++i)
			s=s*power(i+1,fac[t][i])%mod;
		ans=(ans+s)%mod;
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	work();
	return 0;
}