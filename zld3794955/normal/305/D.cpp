#include<bits/stdc++.h>
using namespace std;
const int N=1000100,M=100100,K=1000100,mod=1000000007;
int n,m,k,l=N,r=0,tot=0,p[K]={1};
int main()
{	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		if(v-u>1)
		{
			if(v-u!=k+1)
			{
				puts("0");
				return 0;
			}
			l=min(l,u);
			r=max(r,u);
			++tot;
		}
	}
	for(int i=1;i<=k;++i)
		p[i]=p[i-1]*2%mod;
	if(l==N && r==0)
	{
		int ans=1;
		for(int i=1;i<=n-k+1;++i)
			ans=(ans+p[min(k,n-i-k-1)])%mod;
		printf("%d\n",ans);
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n-k+1;++i)
			if(i<=l && i+k>=r)
				ans=(ans+p[min(k,n-i-k-1)-tot+(i==l)])%mod;
		printf("%d\n",ans);
	}
	return 0;
}