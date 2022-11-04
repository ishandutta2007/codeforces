#include<cstdio>
#define N 3005
using namespace std;
int f[N*N*2],S[N*N*2],T[N*N*2];
bool vis[N][N*2];int n,m,Q,x,y,ans,i,j;
inline int id(int x,int y){
	return (x-1)*m*2+y;
}
int _get(int u){
	return f[u]==u?u:f[u]=_get(f[u]);
}
int get(int u){
    if (f[u]==u) return u;
    S[++*S]=u;T[*S]=f[u];
    return f[u]=get(f[u]);
}
void Union(int x,int y,int F){
    if (y<1) y+=2*m;
	if (y>2*m) y-=2*m;
    if (x<1||x>n||!vis[x][y]) return;
    int u=get(id(x,y));
    if (f[u]==F) return;
    S[++*S]=u,T[*S]=f[u];f[u]=F;
}
int work(int x,int y){
    int F=get(id(x,y));
    Union(x-1,y-1,F);Union(x-1,y,F);Union(x-1,y+1,F);
    Union(x,y-1,F);Union(x,y+1,F);
    Union(x+1,y-1,F);Union(x+1,y,F);Union(x+1,y+1,F);
}
int main(){
    scanf("%d%d%d",&n,&m,&Q);
    for (i=1;i<=n;i++)
        for (j=1;j<=m*2;j++)
            f[id(i,j)]=id(i,j);
	int ans=Q;
    while (Q--){
        scanf("%d%d",&x,&y);*S=0;
        if (vis[x][y]) continue;
        vis[x][y]=vis[x][y+m]=1;
        work(x,y); work(x,y+m);
        if (get(id(x,y))!=get(id(x,y+m))) continue;
        ans--; vis[x][y]=vis[x][y+m]=0;
        for (i=*S;i;i--) f[S[i]]=T[i];
	}
	printf("%d\n",ans);
}