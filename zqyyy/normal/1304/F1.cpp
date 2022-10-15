#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=57,M=20007;
int n,m,mx,K,s[N][M],d[N][M],f[N][M];
struct Segment_Tree{
    int t[M<<2],tg[M<<2];
#define ls (p<<1)
#define rs (p<<1|1)
    inline void upd(int p){t[p]=max(t[ls],t[rs]);}
    void build(int p,int l,int r,int now){
	tg[p]=0;if(l==r){t[p]=f[now][l]+s[now+1][l+K-1]-s[now+1][l-1];return;}
	int mid=(l+r)>>1;build(ls,l,mid,now),build(rs,mid+1,r,now),upd(p);
    }
    inline void pt(int p,int v){t[p]+=v,tg[p]+=v;}
    inline void spread(int p){
	if(tg[p])pt(ls,tg[p]),pt(rs,tg[p]),tg[p]=0;
    }
    void modify(int p,int l,int r,int x,int y,int v){
	if(x<=l && r<=y)return pt(p,v);
	spread(p);int mid=(l+r)>>1;
	if(x<=mid)modify(ls,l,mid,x,y,v);
	if(y>mid)modify(rs,mid+1,r,x,y,v);
	upd(p);
    }
}T;
inline void add(int p,int now){T.modify(1,1,mx,max(1,p-K+1),min(mx,p),-d[now][p]);}
inline void del(int p,int now){T.modify(1,1,mx,max(1,p-K+1),min(mx,p),d[now][p]);}
int main(){
    n=read(),m=read(),K=read(),mx=m-K+1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    d[i][j]=read(),s[i][j]=s[i][j-1]+d[i][j];
    for(int i=1;i<=mx;i++)f[1][i]=s[1][i+K-1]-s[1][i-1];
    for(int i=2;i<=n;i++){
	T.build(1,1,mx,i-1);
	for(int j=1;j<K;j++)add(j,i);
	for(int j=1;j<=mx;j++){
	    int l=j,r=j+K-1;
	    if(l>1)del(l-1,i);
	    add(r,i),f[i][j]=T.t[1]+s[i][r]-s[i][l-1];
	}
    }
    int ans=0;
    for(int i=1;i<=mx;i++)ans=max(ans,f[n][i]);
    printf("%d\n",ans);
    return 0;
}