#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll f[2010][2010];//i%mj 
ll g[2010];
char s1[2010];
char s2[2010];
int a[2010];
int b[2010];
int len;
int v;
int m,d;
ll check(char *s)
{
	int i,j;
	for(i=1;i<=len;i++)
		a[i]=s[len-i+1]-'0';
	ll ans=0;
	for(i=len;i>=1;i--)
	{
		if(i%2==v&&a[i]!=d||i%2!=v&&a[i]==d)
			return 0;
		ans=ans*10+a[i];
		ans%=m;
	}
	return !ans;
}
ll solve(char *s)
{
	int i,j;
	for(i=1;i<=len;i++)
		a[i]=s[len-i+1]-'0';
	ll ans=0;
	ll p=0;
	for(i=len;i>=0;i--)
	{
		if(!i)
		{
			if(!p)
				ans++;
			break;
		}
		if(i%2==v)
		{
			if(a[i]<d)
				break;
			if(a[i]>d)
			{
				ans+=f[i-1][((-p-d*g[i-1])%m+m)%m];
				break;
			}
			p=(p+a[i]*g[i-1])%m;
		}
		else
		{
			for(j=(i==len?1:0);j<a[i];j++)
				if(j!=d)
					ans+=f[i-1][((-p-j*g[i-1])%m+m)%m];
			p=(p+a[i]*g[i-1])%m;
			if(a[i]==d)
				break;
		}
	}
	ans%=mod;
	return ans;
}
int main()
{
//	freopen("cf628d.in","r",stdin);
//	freopen("cf628d.out","w",stdout);
	scanf("%d%d",&m,&d);
	scanf("%s",s1+1);
	int i;
	len=strlen(s1+1);
	scanf("%s",s2+1);
	memset(f,0,sizeof f);
	v=(len%2?0:1);
	int j,k;
	g[0]=1%m;
	f[0][0]=1;
	for(i=1;i<=2001;i++)
	{
		g[i]=g[i-1]*10%m;
		if(i%2==v)
		{
			for(j=0;j<m;j++)
				f[i][(j+d*g[i-1])%m]+=f[i-1][j];
		}
		else
		{
			for(k=0;k<=9;k++)
				if(k!=d)
					for(j=0;j<m;j++)
						f[i][(j+k*g[i-1])%m]+=f[i-1][j];
		}
		for(j=0;j<m;j++)
			f[i][j]%=mod;
	}
	ll ans=0;
//	printf("%I64d\n",solve(s2));
//	printf("%I64d\n",solve(s1));
	ans+=solve(s2);
	ans-=solve(s1);
	ans+=check(s1);
	ans=(ans+mod)%mod;
	printf("%I64d\n",ans);
	return 0;
}