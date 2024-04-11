#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=500010,INF=0x3f3f3f3f;
int n,m;
struct Segment{int l,r,w;}s[N];
namespace SegmentTree{
#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
int minx[N<<4],tag[N<<4],tot;
void pushup(int now){
    minx[now]=min(minx[lson],minx[rson]);
}
void pushdown(int now){
    if(tag[now]){
        tag[lson]+=tag[now],minx[lson]+=tag[now];
        tag[rson]+=tag[now],minx[rson]+=tag[now];
        tag[now]=0;
    }
}
void modify(int now,int l,int r,int x,int y,int val){
    if(x<=l&&r<=y){
        tag[now]+=val,minx[now]+=val;
        return;
    }
    pushdown(now);
    if(x<=mid) modify(lson,l,mid,x,y,val);
    if(y>mid) modify(rson,mid+1,r,x,y,val);
    pushup(now);
}
int query(int now,int l,int r,int x,int y){
    if(x<=l&&r<=y) return minx[now];
    pushdown(now);
    int tmp=INF;
    if(x<=mid) tmp=min(tmp,query(lson,l,mid,x,y));
    if(y>mid) tmp=min(tmp,query(rson,mid+1,r,x,y));
    return tmp;
}
}
using namespace SegmentTree;

int ans=INF;
int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) s[i].l=rdi(),s[i].r=rdi()-1,s[i].w=rdi();
    m--;
    sort(s+1,s+n+1,[&](const Segment &a,const Segment &b){return a.w<b.w;});
    for(int l=1,r=1;l<=n;l++){
        while(r<=n&&!query(1,1,m,1,m)) modify(1,1,m,s[r].l,s[r].r,1),r++;
        if(query(1,1,m,1,m)) ans=min(ans,s[r-1].w-s[l].w);
        modify(1,1,m,s[l].l,s[l].r,-1);
    }
    cout<<ans<<endl;
    return 0;
}