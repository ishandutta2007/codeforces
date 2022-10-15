#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,d[100010],w[100010],w1[100010],tot;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&w[i]);
		for(int i=1,x,y;i<n;++i)scanf("%d %d",&x,&y),++d[x],++d[y];
		long long ans=0;
		for(int i=1;i<=n;++i)ans+=w[i];
		tot=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<d[i];++j)
				w1[++tot]=w[i];
		sort(w1+1,w1+1+tot,[&](int x,int y){return x>y;});
		for(int i=1;i<n;++i)printf("%lld ",ans),ans+=w1[i];printf("\n");
		for(int i=1;i<=n;++i)d[i]=0;
	}
	return 0;
}