#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n,m;
int a[maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for (int x,i=0;i<n;++i)
		scanf("%d",&x),++a[x];
	
	int cnt=0,sum=0;
	for (int i=1;i<maxn;++i)
	{
		if (!a[i])	continue;
		++cnt;
		sum=max(sum,(a[i]-1)/m+1);
	}
	printf("%d\n",m*sum*cnt-n);
	return 0;
}