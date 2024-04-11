#include<bits/stdc++.h>
using namespace std;
const int N=100010,V=108;
int n,q,a[N]={};
double p[N][V]={},ans=0;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p[i][a[i]]=1;
		ans+=!a[i];
	}
}
double C(double n,int m)
{
	double s=1;
	for(int i=0;i<m;++i)
		s*=(n-i)/(i+1);
	return s;
}
void work()
{
	scanf("%d",&q);
	int u,v,k;
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%d",&u,&v,&k);
		ans-=p[u][0];
		for(int j=0;j<=100;++j)
		{
			double tmp=p[u][j],d=1.0/C(a[u],k);
			p[u][j]=0;
			for(int l=0;l<=k && l<=j;++l)
				p[u][j-l]+=C(a[u]-j,k-l)*C(j,l)*d*tmp;
		}
		a[u]-=k,a[v]+=k;
		ans+=p[u][0];
		printf("%.12f\n",ans);
	}
}
int main()
{	
	init();
	work();
	return 0;
}