#include<bits/stdc++.h>
#define maxn 2050
using namespace std;
typedef long long LL;

int n,m;

LL x;
LL a[maxn],b[maxn];
LL A[maxn],B[maxn];

void prepare(int n,LL a[],LL A[])
{
	for (int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;++i)
	{
		LL sum=0;
		for (int j=i;j<=n;++j)
			A[j-i+1]=min(A[j-i+1],sum+=a[j]);
	}
}

void init()
{
	memset(A,0x3f,sizeof(A));
	memset(B,0x3f,sizeof(B));
	scanf("%d%d",&n,&m);
	prepare(n,a,A);
	prepare(m,b,B);
	scanf("%lld",&x);
}

void solve()
{
	LL ans=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (A[i]*B[j]<=x)
				ans=max(ans,1LL*i*j);
	cout<<ans<<endl;
}

int main()
{
	init();
	solve();
	return 0;
}