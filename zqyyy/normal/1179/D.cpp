#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
inline ll sqr(int x){return 1ll*x*x;}
const int N=5e5+7;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
    e[++s_e]={y,head[x]},head[x]=s_e;
}
int n,sz[N];
void dfs1(int x,int fa){
    sz[x]=1;
    for(int i=head[x],y;i;i=e[i].nxt)
	if((y=e[i].to)!=fa)dfs1(y,x),sz[x]+=sz[y];
}
int rt;
ll res;
void dfs(int x,int fa,ll sum){
    if(res>sum)res=sum,rt=x;
    for(int i=head[x],y;i;i=e[i].nxt)
	if((y=e[i].to)!=fa)dfs(y,x,sum-sqr(sz[x])+sqr(sz[y])+sqr(sz[x]-sz[y]));
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	add_e(x,y),add_e(y,x);
    }
    dfs1(1,0),res=1e18;
    dfs(1,0,sqr(n)),res=1e18;
    dfs1(rt,0),dfs(rt,0,sqr(n));
    printf("%lld\n",(1ll*n*(n-1)+sqr(n)-res)/2);
    return 0;
}