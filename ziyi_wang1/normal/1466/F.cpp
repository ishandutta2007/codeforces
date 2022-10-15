#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int f[500050];
bool used[500050];
int find(int x)
{
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
bool ins(int x,int y)
{
	if(find(x)==find(y))return 0;
	f[find(x)]=find(y);
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)f[i]=i;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int k,x,y=0;
		scanf("%d",&k);
		scanf("%d",&x);
		if(k==2)scanf("%d",&y);
		if(ins(x,y))used[i]=1,++ans;
	}
	int po=1;
	for(int i=1;i<=ans;++i)po=2*po%1000000007;
	printf("%d %d\n",po,ans);
	for(int i=1;i<=n;++i)if(used[i])printf("%d ",i);
	return 0;
}