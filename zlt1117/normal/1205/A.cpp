#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int maxn=1e6+5;
int n;
int a[maxn];
int main()
{
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	scanf("%d",&n);
	if(n&1)
	{
		printf("YES\n");
		for(int i=1,j=1;i<=n;++i,j+=2)
		{
			if(i&1)a[i]=j,a[i+n]=j+1;
			else a[i+n]=j,a[i]=j+1;
		}
		FOR(i,1,2*n)printf("%d ",a[i]);
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}