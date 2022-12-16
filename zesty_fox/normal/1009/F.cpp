#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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
#define mp make_pair
#define pb push_back

const int N=1000010;
int n,head[N],tot;
struct Edge{int to,nxt;}e[N<<1];

void addedge(int x,int y){
    e[++tot]={y,head[x]};
    head[x]=tot;
}

namespace SegTree{

#define mid ((l+r)>>1)

const int M=N*22;

struct Node{int maxn,pos;}t[M];
int ls[M],rs[M],rt[N],tot;

Node operator + (Node a,Node b){
    return {max(a.maxn,b.maxn),a.maxn<b.maxn?b.pos:a.pos};
}

void pushup(int now){
    t[now]=t[ls[now]]+t[rs[now]];
}

int newnode(){return ++tot;}

void add(int &now,int l,int r,int x,int val){
    if(!now) now=newnode();
    if(l==r){
        t[now].pos=l,t[now].maxn+=val;
        return;
    }
    if(x<=mid) add(ls[now],l,mid,x,val);
    else add(rs[now],mid+1,r,x,val);
    pushup(now);
}

void merge(int &now1,int now2,int l,int r){
    if(!now1||!now2){
        now1|=now2;
        return;
    }
    if(l==r){
        t[now1].maxn+=t[now2].maxn;
        t[now1].pos=l;
        return;
    }
    merge(ls[now1],ls[now2],l,mid);
    merge(rs[now1],rs[now2],mid+1,r);
    pushup(now1);
}

#undef mid
}
using SegTree::rt;

int res[N];
void dfs(int x,int fa,int dep){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs(y,x,dep+1);
        SegTree::merge(rt[x],rt[y],1,n);
    }
    SegTree::add(rt[x],1,n,dep,1);
    res[x]=SegTree::t[rt[x]].pos-dep;
}

int main(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y),addedge(y,x);
    }
    dfs(1,0,1);
    for(int i=1;i<=n;i++) printf("%d\n",res[i]);
    return 0;
}