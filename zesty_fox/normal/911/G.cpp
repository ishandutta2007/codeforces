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

const int N=200010,M=110;
int n,q,a[N];

#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)

int p[N<<2][M];

void pushdown(int now){
    for(int i=1;i<=M-10;i++){
        p[lson][i]=p[now][p[lson][i]],p[rson][i]=p[now][p[rson][i]];
    }
    for(int i=1;i<=M-10;i++) p[now][i]=i;
}

void build(int now,int l,int r){
    for(int i=1;i<=M-10;i++) p[now][i]=i;
    if(l==r) return;
    build(lson,l,mid);build(rson,mid+1,r);
}

void modify(int now,int l,int r,int x,int y,int fr,int to){
    if(fr==to) return;
    if(x<=l&&r<=y){
        for(int i=1;i<=M-10;i++){
            if(p[now][i]==fr) p[now][i]=to;
        }
        return;
    }
    pushdown(now);
    if(x<=mid) modify(lson,l,mid,x,y,fr,to);
    if(y>mid) modify(rson,mid+1,r,x,y,fr,to);
    return;
}

int query(int now,int l,int r,int x,int val){
    if(l==x&&x==r) return p[now][val];
    pushdown(now);
    if(x<=mid) return query(lson,l,mid,x,val);
    else return query(rson,mid+1,r,x,val);
}

int main(){
    n=rdi();build(1,1,n);
    for(int i=1;i<=n;i++) a[i]=rdi();
    q=rdi();
    while(q--){
        int l=rdi(),r=rdi(),x=rdi(),y=rdi();
        modify(1,1,n,l,r,x,y);
    }
    for(int i=1;i<=n;i++) printf("%d ",query(1,1,n,i,a[i]));
    puts("");
    return 0;
}