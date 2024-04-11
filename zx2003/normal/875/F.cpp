#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int f[N],n,m,i,x,y,ans;
bool b[N];
struct edge{
	int a,b,w;
	inline bool operator<(const edge&rhs)const{
		return w>rhs.w;
	}
}e[N];
int gfa(int x){
	return f[x]==x?x:f[x]=gfa(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
	sort(e+1,e+m+1);for(i=1;i<=n;++i)f[i]=i;
	for(i=1;i<=m;++i){
		x=gfa(e[i].a),y=gfa(e[i].b);
		if(x!=y){
			if(!b[x] || !b[y])f[x]=y,ans+=e[i].w,b[y]|=b[x];
		}else if(!b[x])b[x]=1,ans+=e[i].w;
	}
	return printf("%d\n",ans),0;
}