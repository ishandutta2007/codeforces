#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int u,v,l,n,m,x[505]={};
	double ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&l);
		ans=max(ans,(double)(x[u]+x[v])/l);
	}
	printf("%.15f\n",ans);
}