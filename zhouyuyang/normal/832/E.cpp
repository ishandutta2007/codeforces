#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n,m,q,cnt;
long long ans;
char str[510];
int v[510][1010],imp[510];
int ine(int x)
{
	return x*x*x%5;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,k,now;
	for(i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(j=1;j<=m;j++)	v[j][i]=str[j]-'a';
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%s",str+1);
		for(j=1;j<=m;j++)	v[j][n+i]=str[j]-'a';
	}
	for(now=i=1;i<=m&&now<=n;i++,now++)
	{
		for(j=i+1;j<=m;j++)	if(v[j][now]>v[i][now])	for(k=now;k<=n+q;k++)	swap(v[j][k],v[i][k]);
		while(!v[i][now]&&now<=n)	now++,cnt++;
		if(now>n)	break;
		int t=ine(v[i][now]);
		for(k=now;k<=n+q;k++)	v[i][k]=v[i][k]*t%5;
		for(j=i+1;j<=m;j++)	if(v[j][now])
		{
			t=v[j][now];
			for(k=now;k<=n+q;k++)	v[j][k]=((v[j][k]-t*v[i][k])%5+5)%5;
		}
	}
	if(now<=n)	cnt+=n-now+1;
	for(;i<=m;i++)	for(k=n+1;k<=n+q;k++)	if(v[i][k])	imp[k-n]=1;
	for(ans=1,i=1;i<=cnt;i++)	ans=ans*5%1000000007;
	for(i=1;i<=q;i++)	printf("%I64d\n",imp[i]?0ll:ans);
	return 0;
}