#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 15005
using namespace std;

int n;

int f[maxn];

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&f[i]);
}

void solve()
{
	bool flag=0;
	for (int i=1;i<=n;++i)
		if (f[f[f[i]]]==i)
			flag=1;
	printf(flag?"YES":"NO");
}

int main()
{
//	freopen("c.in","r",stdin);
	init();
	solve();
	return 0;
}