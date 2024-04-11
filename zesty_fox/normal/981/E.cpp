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
#define rdl read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=10010;
bitset<N> res[N],res1[21],ans;
int n,q;
vi tag[N<<2],s;

#define lson (now<<1)
#define rson (now<<1|1)
#define mid ((l+r)>>1)
void add(int now,int l,int r,int x,int y,int val){
    if(x<=l&&r<=y){
        tag[now].pb(val);
        return;
    }
    if(x<=mid) add(lson,l,mid,x,y,val);
    if(y>mid) add(rson,mid+1,r,x,y,val);
}

void dfs(int now,int l,int r,int dep){
    res1[dep]=res1[dep-1];
    for(auto x:tag[now]) res1[dep]|=(res1[dep]<<x);
    if(l==r){
        res[l]=res1[dep];
        return;
    }
    dfs(lson,l,mid,dep+1);
    dfs(rson,mid+1,r,dep+1);
}

#undef lson
#undef rson
#undef mid

int main(){
    n=rdi(),q=rdi();
    for(int i=1;i<=q;i++){
        int l=rdi(),r=rdi(),x=rdi();
        add(1,1,n,l,r,x);
    }
    res1[0]=1;dfs(1,1,n,1);
    for(int i=1;i<=n;i++) ans|=res[i];
    for(int i=1;i<=n;i++){
        if(ans[i]) s.pb(i);
    }
    printf("%ld\n",s.size());
    for(auto k:s) printf("%d ",k);
    puts("");
    return 0;
}