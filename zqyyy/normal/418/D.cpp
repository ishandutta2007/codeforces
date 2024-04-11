#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
    e[++s_e]=(Edge){y,head[x]},head[x]=s_e;
}
int zj,rt1,rt2,fa[N],top[N];
bool v[N];
vector<int>pos;
void dfs(int x,int pa,int dep){
    fa[x]=pa;
    if(dep>zj)zj=dep,rt1=x;
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;
	if(y^pa)dfs(y,x,dep+1);
    }
}
int f[N],dep[N];
void dfs1(int x,int pa,int D,int tf){
    dep[x]=D,top[x]=tf,f[tf]=max(f[tf],dep[x]);
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;
	if(!v[y] && y!=pa)dfs1(y,x,D+1,tf);
    }
}
int n,m,st[2][N][17],lg[N];
inline int query(int i,int l,int r){
    if(l>r)return -1e9;int k=lg[r-l+1];
    return max(st[i][l][k],st[i][r-(1<<k)+1][k]);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	add_e(x,y),add_e(y,x);
    }
    dfs(1,0,0),rt2=rt1,zj=0,dfs(rt2,0,0);
    int X=rt1;pos.push_back(0),pos.push_back(X),v[X]=1;
    while(X^rt2)pos.push_back(X=fa[X]),v[X]=1;
    m=pos.size()-1;
    for(int i=1;i<=m;i++)dfs1(pos[i],0,0,i);
    for(int i=2;i<=m;i++)lg[i]=lg[i>>1]+1;
    for(int i=1;i<=m;i++)st[0][i][0]=f[i]+i,st[1][i][0]=f[i]-i;
    for(int k=0;k<2;k++)
	for(int j=1;j<=lg[m];j++)
	    for(int i=1;i+(1<<j)-1<=m;i++)
		st[k][i][j]=max(st[k][i][j-1],st[k][i+(1<<(j-1))][j-1]);
    int Q=read(),ans=0;
    while(Q--){
	int x=read(),y=read();
	if(top[x]==top[y]){
	    printf("%d\n",ans=max(top[x]-1,m-top[x])+min(dep[x],dep[y]));
	    continue;
	}
	if(top[x]>top[y])swap(x,y);
//	ans=max(min(dep[y]+top[y],dep[x]+top[x]),min(dep[y]+m-top[y],dep[x]+m-top[x]));
	int mid=-dep[x]+dep[y]+top[y]+top[x];
	if((top[x]<<1)>=mid)ans=dep[y]+max(m-top[y],top[y]-1);
	else if((top[y]<<1)<=mid)ans=dep[x]+max(m-top[x],top[x]-1);
	else ans=max(max(query(0,top[x]+1,mid>>1)-top[x],top[x]-1)+dep[x],max(m-top[y],query(1,(mid>>1)+1,top[y]-1)+top[y])+dep[y]);
	printf("%d\n",ans);
    }
    return 0;
}