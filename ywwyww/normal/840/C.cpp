#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll p=1000000007;
ll f[510][510];
ll a[510];
int b[510];
ll c[510][510];
ll fac[510];
ll getc(int x,int y)
{
	if(x<y)
		return 0;
	return c[x][y];
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	fac[0]=1;
	for(i=1;i<=500;i++)
		fac[i]=fac[i-1]*i%p;
	for(i=0;i<=500;i++)
	{
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		for(j=2;j<=100000;j++)
		{
			ll v=ll(j)*j;
			while(a[i]%v==0)
				a[i]/=v;
		}
	}
	sort(a+1,a+n+1);
	int m=0;
	for(i=1;i<=n;i=j+1)
	{
		j=i;
		while(j<n&&a[j+1]==a[i])
			j++;
		b[++m]=j-i+1;
	}
	sort(b+1,b+m+1,greater<int>());
	memset(f,0,sizeof f);
	f[1][b[1]-1]=1;
	int k,l;
	int s=0;
	b[0]=0;
	for(i=1;i<m;i++)
	{
		s+=b[i];
		for(j=0;j<s;j++)
			if(f[i][j])
				for(k=1;k<=b[i+1];k++)
					for(l=0;l<=k&&l<=j;l++)
						(f[i+1][j+b[i+1]-k-l]+=f[i][j]*getc(b[i+1]-1,k-1)%p*getc(j,l)%p*getc(s-j+1,k-l)%p)%=p;
	}
	ll ans=f[m][0];
	for(i=1;i<=m;i++)
		ans=ans*fac[b[i]]%p;
	printf("%I64d\n",ans);
	return 0;
}