#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#define xxx 2010
using namespace std;
int n,m,a[xxx],b[xxx],c[xxx],d[xxx],low=0,ans=0;
map<int,int>mp;

int pd(int st)
{
	int t=b[1]-c[st];
	if (mp[t]) return 0;
	mp[t]=1;
	for (int i=1;i<=n;i++)
		d[i]=c[i]+t;
	int p=0;
	for (int j=1;j<=m;j++)
	{
		p++;
		while (d[p]!=b[j]&&p<=n) p++;
		if (p>n) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	c[0]=0;
	for (int i=1;i<=n;i++)
		c[i]=c[i-1]+a[i];
	sort(c+1,c+n+1);
	for (int i=1;i<=n-m+1;i++)
		if (pd(i))
			ans++;
	cout<<ans;
}