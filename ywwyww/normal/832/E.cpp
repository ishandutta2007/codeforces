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
int inv[10];
int a[1010][1010];
int c[1010][1010];
char s[1010];
int ans[1010];
int n,m;
int b[1010];
int x[1010];
int d[1010];
ll solve()
{
	memset(x,-1,sizeof x);
	int i,j;
	for(i=1;i<=m;i++)
		if(b[i])
		{
			int ss=0;
			for(j=1;j<=n;j++)
				if(j!=b[i])
					ss=(ss+x[j]*c[j][i])%5;
			x[b[i]]=(s[i]-'a'-ss+5)%5*inv[c[b[i]][i]]%5;
		}
		else
		{
			int ss=0;
			for(j=1;j<=n;j++)
				ss=(ss+x[j]*c[j][i])%5;
			if(ss!=s[i]-'a')
				return 0;
		}
	ll ans=1;
	for(i=1;i<=n;i++)
		if(x[i]==-1)
			ans=ans*5%1000000007;
	return ans;
}
int main()
{
	inv[0]=inv[1]=1;
	inv[2]=3;
	inv[3]=2;
	inv[4]=4;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;j++)
			a[i][j]=s[j]-'a';
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			c[i][j]=a[i][j];
	int k,l;
	memset(d,0,sizeof d);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			if(c[j][i]&&!d[j])
				break;
		if(j>n)
			continue;
		d[j]=i;
		b[i]=j;
		int p;
		for(k=1;k<=n;k++)
			if(c[k][i]&&!d[k])
			{
				p=inv[c[j][i]]*c[k][i]%5;
				for(l=i;l<=m;l++)
					c[k][l]=(c[k][l]-p*c[j][l]%5+5)%5;
			}
	}
	int q;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%s",s+1);
		printf("%I64d\n",solve());
	}
	return 0;
}