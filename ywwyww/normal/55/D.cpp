#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
ll f[2][2][50][2530];//iik2520l 
ll a[20];
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
ll getgcd(int x)
{
	int i;
	int s=1;
	for(i=1;i<=9;i++)
		if(x&(1<<(i-1)))
			s=s/gcd(s,i)*i;
	return s;
}
ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}
int to[3000][20];
int t2[3000][20];
ll *o[520][2530];
int cnt;
int c1[2520];
int c2[2520];
ll dp(ll v)
{
	if(!v)
		return 0;
	memset(a,0,sizeof a);
	int i;
	for(i=0;v;i++)
	{
		a[i]=v%10;
		v/=10;
	}
	int j,k,l;
	int t=0;
	memset(f[t],0,sizeof f[t]);
	f[t][1][1][0]=1;
	int st=0;
	i++;
	for(;i;i--)
	{
		memset(f[t^1],0,sizeof f[t^1]);
		for(k=1;k<=cnt;k++)
			for(l=0;l<=2519;l++)
				f[t^1][1][t2[k][a[i-1]]][to[l][a[i-1]]]+=f[t][1][k][l];
		for(k=1;k<=cnt;k++)
			for(l=0;l<=2519;l++)
				o[k][l]=&f[t^1][0][k][l];
		for(k=1;k<=cnt;k++)
			for(l=0;l<=2519;l++)
			{
				ll v0=f[t][0][k][l];
				ll v1=f[t][1][k][l];
				if(v1)
					for(j=1;j<a[i-1];j++)
						*o[t2[k][j]][to[l][j]]+=v1;
				if(v0)
					for(j=1;j<=9;j++)
						*o[t2[k][j]][to[l][j]]+=v0;
				if(st)
				{
					if(v0)
						*o[k][to[l][0]]+=v0;
					if(v1&&a[i-1])
						*o[k][to[l][0]]+=v1;
				}
			}
		st=1;
		t^=1;
	}
	ll ans=0;
	for(i=1;i<=cnt;i++)
		for(j=0;j<=2519;j++)
			if(j%c1[i]==0)
			{
//				if(f[t][0][i][j]+f[t][1][i][j])
//					printf("%d %d %I64d\n",i,j,f[t][0][i][j]+f[t][1][i][j]);
				ans+=f[t][0][i][j]+f[t][1][i][j];
			}
	return ans-1;
}
int main()
{
//	freopen("cf55d.in","r",stdin);
//	freopen("cf55d.out","w",stdout);
	int i;
	int j;
	for(i=1;i<=2520;i++)
		if(2520%i==0)
		{
			cnt++;
			c1[cnt]=i;
			c2[i]=cnt;
		}
	for(i=1;i<=cnt;i++)
	{
		t2[i][0]=i;
		for(j=1;j<=9;j++)
			t2[i][j]=c2[lcm(c1[i],j)];
	}
	ll l,r;
	for(i=0;i<=2519;i++)
		for(j=0;j<=9;j++)
			to[i][j]=(i*10+j)%2520;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0;
		scanf("%I64d%I64d",&l,&r);
		int i;
		ans=dp(r)-dp(l-1);
		printf("%I64d\n",ans);
	}
	return 0;
}