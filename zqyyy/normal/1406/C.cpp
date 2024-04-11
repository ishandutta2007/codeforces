#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
const int N=1e6+7,inf=1e9;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
    e[++s_e]={y,head[x]},head[x]=s_e;
}
int n,sz[N];
vector<int>zx;
void dfs(int x,int fa){
    sz[x]=1;int max_sz=0;
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;
	if(y==fa)continue;
	dfs(y,x),sz[x]+=sz[y];
	max_sz=max(max_sz,sz[y]);
    }
    max_sz=max(max_sz,n-sz[x]);
    if(max_sz<=n/2)zx.push_back(x);
}
inline void clear(){
    s_e=0,zx.clear();
    for(int i=1;i<=n;i++)head[i]=0;
}
inline void work(){
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	add_e(x,y),add_e(y,x);
    }
    dfs(1,0);
    if((int)zx.size()==1){
	int x=e[head[1]].to;
	printf("%d %d\n%d %d\n",1,x,1,x);
	return;
    }
    int x=e[head[zx[0]]].to;
    if(x==zx[1])x=e[e[head[zx[0]]].nxt].to;
    printf("%d %d\n%d %d\n",x,zx[0],x,zx[1]);
}
int main(){
    int test=read();
    while(test--)work(),clear();
    return 0;
}