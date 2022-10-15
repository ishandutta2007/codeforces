#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e6+7;
int tot,lsh[N<<1];
struct b1t{
    int n,c[N<<1];
#define lbt(x) ((x)&-(x))
    inline void clear(int _n){n=_n;for(int i=1;i<=n;i++)c[i]=0;}
    inline void add(int p,int x){for(;p<=n;p+=lbt(p))c[p]+=x;}
    inline int ask(int p){int res=0;for(;p;p-=lbt(p))res+=c[p];return res;}
}T;
int n,m,a[N],b[N],id[N];
struct A{
    int num,pos;
    bool operator <(const A &q) const {return num^q.num?num<q.num:pos<q.pos;}
};
struct Segment_Tree{
    A t[N<<2];int tg[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
    inline void upd(int p){t[p]=min(t[ls],t[rs]);}
    void build(int p,int l,int r){
	t[p]={0,l},tg[p]=0;if(l==r)return;
	int mid=(l+r)>>1;
	build(ls,l,mid),build(rs,mid+1,r),upd(p);
    }
    inline void spread(int p){
	if(tg[p])t[ls].num+=tg[p],t[rs].num+=tg[p],tg[ls]+=tg[p],tg[rs]+=tg[p],tg[p]=0;
    }
    void modify(int p,int l,int r,int x,int y,int v){
	if(x<=l && r<=y){t[p].num+=v,tg[p]+=v;return;}
	spread(p);int mid=(l+r)>>1;
	if(x<=mid)modify(ls,l,mid,x,y,v);
	if(y>mid)modify(rs,mid+1,r,x,y,v);
	upd(p);
    }
    A query(int p,int l,int r,int x,int y){
	if(x<=l && r<=y)return t[p];
	spread(p);int mid=(l+r)>>1;
	if(y<=mid)return query(ls,l,mid,x,y);
	if(x>mid)return query(rs,mid+1,r,x,y);
	return min(query(ls,l,mid,x,mid),query(rs,mid+1,r,mid+1,y));
    }
}t;
inline void work(){
    n=read(),m=read(),tot=0;
    for(int i=1;i<=n;i++)a[i]=lsh[++tot]=read(),id[i]=i;
    for(int i=1;i<=m;i++)b[i]=lsh[++tot]=read();
    sort(lsh+1,lsh+tot+1),tot=unique(lsh+1,lsh+tot+1)-lsh-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+tot+1,a[i])-lsh;
    for(int i=1;i<=m;i++)b[i]=lower_bound(lsh+1,lsh+tot+1,b[i])-lsh;
    sort(b+1,b+m+1),T.clear(tot);ll ans=0;
    for(int i=n;i;i--)ans+=T.ask(a[i]-1),T.add(a[i],1);
    sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
    t.build(1,0,n);int lst=1,lst1=1,l=0;
    for(int i=1;i<=n;i++)t.modify(1,0,n,i,n,1);
    for(int i=1;i<=m;i++){
	while(lst<=n && a[id[lst]]<=b[i])t.modify(1,0,n,id[lst],n,-1),lst++;
	while(lst1<=n && a[id[lst1]]<b[i])t.modify(1,0,n,id[lst1],n,-1),lst1++;
	A res=t.query(1,0,n,l,n);l=res.pos,ans+=res.num+lst1-1;
    }
    printf("%lld\n",ans);
}
int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int test=read();
    while(test--)work();
    return 0;
}