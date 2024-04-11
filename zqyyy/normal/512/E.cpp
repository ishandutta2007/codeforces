#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=1024;
int n,o;
vector<pii>pre,suf;
bitset<N>e[N];
inline int op(int x,int y){
    if(!o)pre.push_back({x,y});
    e[x][y]=e[y][x]=0;
    bitset<N>tmp=e[x]&e[y];
    int p=tmp._Find_next(1);
    e[1][p]=e[p][1]=1;
    if(o)suf.push_back({1,p});
    return p;
}
inline void solve(int l,int r){
    if(l+1==r)return;
    int mid=op(l,r);
    solve(l,mid),solve(mid,r);
}
inline void work(){
    for(int i=1;i<=n;i++)e[i].set(i%n+1),e[i].set((i+n-2)%n+1);
    int lst=2;
    for(int i=3;i<n;i++)
	if(e[1][i])solve(lst,i),lst=i;
    solve(lst,n);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read();
    for(int i=1;i<=n-3;i++){
	int x=read(),y=read();
	e[x].set(y),e[y].set(x);
    }
    work();
    for(int i=1;i<=n;i++)e[i].reset();
    for(int i=1;i<=n-3;i++){
	int x=read(),y=read();
	e[x].set(y),e[y].set(x);
    }
    o=1,work(),reverse(suf.begin(),suf.end());
    printf("%lu\n",pre.size()+suf.size());
    for(auto [x,y]:pre)printf("%d %d\n",x,y);
    for(auto [x,y]:suf)printf("%d %d\n",x,y);
    return 0;
}