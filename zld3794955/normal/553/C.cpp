#include<bits/stdc++.h>
using namespace std;
const int N=100010,mod=1000000007;
int n,m,root[N]={},c[N]={},tot=0,ans=1;
int get_root(int r)
{
	if(r!=root[r])
	{
		int R=get_root(root[r]);
		c[r]^=c[root[r]];
		root[r]=R;
	}
	return root[r];
}
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		root[i]=i;
	tot=n-1;
	int a,b,x;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&a,&b,&x);
		x=!x;
		int u=get_root(a),v=get_root(b);
		if(u!=v)
		{
			--tot;
			root[u]=v;
			c[u]=c[a]^c[b]^x;
		}
		else
			if((c[a]^c[b])!=x)
			{
				puts("0");
				return 0;
			}
	}
	for(int i=1;i<=tot;++i)
		ans=(ans+ans)%mod;
	printf("%d\n",ans);
	return 0;
}