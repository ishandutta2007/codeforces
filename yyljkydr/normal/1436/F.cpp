#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7,P=998244353;

int n,cnt[N];

int m,f[N],g[N];

int qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

void inc(int &a,int b)
{
	a+=b;
	a>=P?a-=P:0;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	m=100000;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		cnt[x]=y;
	}
	for(int i=1;i<=m;i++)
	{
		int s=0;
		for(int j=i;j<=m;j+=i)
			s+=cnt[j];
		int c1,c2,c3;
		c1=(s>=2?(s-1)%P*qpow(2,s-2)%P:0);
		c2=(s>=3?(s-2)%P*qpow(2,s-3)%P:0)+(s>=2?qpow(2,s-2):0);
		c3=(s>=3?(s-2)%P*qpow(2,s-3)%P:0)+(s>=2?qpow(2,s-2):0);
		int sum=0;
		for(int j=i;j<=m;j+=i)
		{
			inc(g[i],c1*j%P*j%P*cnt[j]%P);
			inc(g[i],c2*j%P*j%P*cnt[j]%P*(cnt[j]-1)%P);
			inc(g[i],2*c3%P*j%P*cnt[j]%P*sum%P);
			inc(sum,j*cnt[j]%P);
		}
	}
	for(int i=m;i>=1;i--)
	{
		f[i]=g[i];
		for(int j=i*2;j<=m;j+=i)
			inc(f[i],P-f[j]);
	}
	cout<<f[1]<<endl;
}