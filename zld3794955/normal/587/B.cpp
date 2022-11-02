#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int N=1000100,K=1000100;
int n,k,a[N]={},v[N]={};
long long l;
vector<int> f[K],t[K];
inline void add(int d,int p,int c)
{
	for(int i=p+1;i<=n;i+=i&(-i))
		(t[d][i]+=c)%=mod;
}
inline int sum(int d,int p)
{
	int s=0;
	for(int i=p+1;i;i-=i&(-i))
		(s+=t[d][i])%=mod;
	return s;
}
void init()
{
	scanf("%d%I64d%d",&n,&l,&k);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	copy(a,a+n,v);
	sort(v,v+n);
	for(int i=0;i<n;++i)
		a[i]=lower_bound(v,v+n,a[i])-v;
}
void work()
{
	for(int i=0;i<k;++i)
		t[i].resize(n+1),f[i].resize(n);
	for(int j=0;j<n;++j)
	{
		f[0][j]=1;
		add(0,a[j],f[0][j]);
	}
	for(int i=1;i<k;++i)
		for(int j=0;j<n;++j)
		{
			f[i][j]=sum(i-1,a[j]);
			add(i,a[j],f[i][j]);
		}
	int d=l%n;
	long long ans=0;
	for(int i=0;i<k;++i)
		for(int j=0;j<n;++j)
		{
			long long tot=max((l/n)+(j<d)-i,0ll)%mod;
			ans+=f[i][j]*tot%mod;
		}
	printf("%I64d\n",ans%mod);
}
int main()
{	
	init();
	work();
	return 0;
}