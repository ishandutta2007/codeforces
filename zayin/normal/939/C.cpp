#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200050
using namespace std;

int n;
int a[maxn];

int num[maxn];

int m,s,f;

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	scanf("%d%d",&s,&f);
	m=f-s;
}

void solve()
{
	for (int i=1;i<n;++i)
		a[i+n]=a[i];
	for (int i=1;i<=m;++i)
		num[1]+=a[i];
	for (int i=2;i<=n;++i)
		num[i]=num[i-1]-a[i-1]+a[i+m-1];
	for (int i=1;i<n;++i)
		num[i+n]=num[i];
	
	int maxi=0;
	for (int i=1;i<=n;++i)
		maxi=max(maxi,num[i]);
	for (int i=1;i<=n;++i)
		if (i<=s)
		{
			if (num[1+s-i]==maxi)
			{
				printf("%d\n",i);
				break;
			}
		} else
		{
			if (num[1+n-i+s]==maxi)
			{
				printf("%d\n",i);
				break;
			}
		}
}

int main()
{
//	freopen("c.in","r",stdin);
	init();
	solve();
	return 0;
}