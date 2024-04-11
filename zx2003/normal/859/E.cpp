#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=200005,mo=1000000007;
int f[N],n,u,v,i,ans=1,sz[N],a[N],j;
int gfa(int x){
	return x==f[x]?x:f[x]=gfa(f[x]);
}
vector<int> b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n<<1;++i)f[i]=i,sz[i]=1;
	for(i=1;i<=n;++i){
		scanf("%d%d",&u,&v);
		int x=gfa(u),y=gfa(v);
		if(x!=y)f[x]=y,sz[y]+=sz[x];
			else a[x]=max(a[x],1+(u==v));
	}
	for(i=1;i<=n<<1;++i)b[gfa(i)].push_back(i);
	for(i=1;i<=n<<1;++i)
		if(gfa(i)==i){
			for(j=v=0;j<(int)b[i].size();++j)v=max(v,a[b[i][j]]);
			if(v==0)ans=1ll*ans*b[i].size()%mo;
			if(v==1)ans=1ll*ans*2%mo;
		}
	printf("%d\n",ans);
	return 0;
}