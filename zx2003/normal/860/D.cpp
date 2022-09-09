#include<cstdio>
#include<vector>
using std::vector;
const int N=200005;
struct edge{
	int to,next,x;
}e[N<<1];
int h[N],n,m,i,u,v,ea[N],eb[N],xb,d[N];
bool vi[N],odd[N];
vector<int> a[N];
void dfs(int x,int fa){
	vi[x]=1,d[x]=d[fa]+1;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa){
		int y=e[i].to;
		if(!vi[y]){
			dfs(y,x);
			if(odd[y])odd[y]^=1,a[y].push_back(e[i].x);
				else odd[x]^=1,a[x].push_back(e[i].x);
		}else if(d[y]<d[x])odd[x]^=1,a[x].push_back(e[i].x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i){
		scanf("%d%d",&u,&v);ea[i]=u,eb[i]=v;
		e[++xb]=(edge){v,h[u],i},h[u]=xb;
		e[++xb]=(edge){u,h[v],i},h[v]=xb;
	}
	for(i=1;i<=n;++i)if(!vi[i])dfs(i,0);
	for(u=0,i=1;i<=n;++i)u+=a[i].size()>>1;
	printf("%d\n",u);
	for(i=1;i<=n;++i)
		for(unsigned int j=0;j+1<a[i].size();j+=2){
			u=a[i][j],v=a[i][j+1];
			printf("%d %d %d\n",ea[u]^eb[u]^i,i,ea[v]^eb[v]^i);
		}
	return 0;
}