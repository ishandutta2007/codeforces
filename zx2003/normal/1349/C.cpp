#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005,M=1e5+5;
int n,m,Q,i,j,x,y,tim,ti[N][N];
ll p;
char c[N][N];
inline int idx(int x,int y){return (x-1)*m+y;}
int g[N*N],sz[N*N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
pair<int,int>q[N*N];int he,ta;
bool inq[N][N];
void tryins(int x,int y){
	if(inq[x][y] || sz[gfa(idx(x,y))]>1)return;
	bool fl=0;
	fl|=x>1 && sz[gfa(idx(x-1,y))]>1;
	fl|=x<n && sz[gfa(idx(x+1,y))]>1;
	fl|=y>1 && sz[gfa(idx(x,y-1))]>1;
	fl|=y<m && sz[gfa(idx(x,y+1))]>1;
	if(!fl)return;
	q[++ta]={x,y};inq[x][y]=1;
}
inline void ext(int x,int y){
	if(x>1)tryins(x-1,y);
	if(x<n)tryins(x+1,y);
	if(y>1)tryins(x,y-1);
	if(y<m)tryins(x,y+1);
}
inline void uni(int x,int y){
	x=gfa(x);y=gfa(y);if(x==y)return;
	sz[x]+=sz[y];g[y]=x;
}
inline int askk(int x,int y){
	return sz[gfa(idx(x,y))]>1?(c[x][y]-'0')^((tim-ti[x][y])&1):c[x][y]-'0';
}
int main(){
//	freopen("1","r",stdin);
	scanf("%d%d%d",&n,&m,&Q);
	for(i=1;i<=n;++i)scanf("%s",c[i]+1);
	for(i=1;i<=n*m;++i)g[i]=i;
	for(i=1;i<=n;++i)for(j=1;j<m;++j)if(c[i][j]==c[i][j+1])g[gfa(idx(i,j))]=gfa(idx(i,j+1));
	for(i=1;i<n;++i)for(j=1;j<=m;++j)if(c[i][j]==c[i+1][j])g[gfa(idx(i,j))]=gfa(idx(i+1,j));
	for(i=1;i<=n*m;++i)++sz[gfa(i)];
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)tryins(i,j);
	int pp=1;
	for(;he<ta;){
		int be=he+1,en=ta;
		++tim;
		for(int ii=be;ii<=en;++ii){
			tie(x,y)=q[ii];
			ti[x][y]=tim;
			if(x>1 && askk(x,y)==askk(x-1,y))uni(idx(x,y),idx(x-1,y));
			if(x<n && askk(x,y)==askk(x+1,y))uni(idx(x,y),idx(x+1,y));
			if(y>1 && askk(x,y)==askk(x,y-1))uni(idx(x,y),idx(x,y-1));
			if(y<m && askk(x,y)==askk(x,y+1))uni(idx(x,y),idx(x,y+1));
			ext(x,y);
		}
		he=en;
	}
//	for(i=1;i<=n;++i)for(j=1;j<=m;++j)printf("%2d%c",gfa(idx(i,j)),j==m?'\n':' ');
//	puts("");
//	for(i=1;i<=n;++i)for(j=1;j<=m;++j)printf("%2d%c",ti[i][j],j==m?'\n':' ');
	for(;Q--;){
		scanf("%d%d%lld",&x,&y,&p);
		putchar(sz[gfa(idx(x,y))]>1 && p>=ti[x][y]?c[x][y]^((p-ti[x][y])&1):c[x][y]);
		putchar('\n');
	}
}