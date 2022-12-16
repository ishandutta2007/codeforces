#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1e6+10;

int n,r1[N],r2[N];
vi e[N];

int mxd[N],mxd2[N],f[N];
void dfs1(int x,int fa){
    f[x]=fa;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs1(y,x);
        int v=mxd[y]+1;
        if(v>mxd[x]) mxd2[x]=mxd[x],mxd[x]=v;
        else if(v>mxd2[x]) mxd2[x]=v;
    }
}

vi v[N];
int up[N];
void dfs2(int x,int fa){
    if(x!=1) v[up[x]].pb(x);
    for(auto y:e[x])
        if(y!=fa) v[mxd[y]+1].pb(x);
    for(auto y:e[x]){
        if(y==fa) continue;
        up[y]=max(up[x]+1,(mxd[x]==mxd[y]+1?mxd2[x]+1:mxd[x]+1));
        dfs2(y,x);
    }
}

int cnt[N],mxs[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    dfs1(1,0),dfs2(1,0);
    for(int i=n;i>=1;i--){
        int lst=0;
        for(auto x:v[i]){
            cnt[x]++;
            if(f[x]) mxs[f[x]]=max(mxs[f[x]],cnt[x]);
            r2[i]=max({r2[i],cnt[x]+mxs[x]-2,cnt[x]+cnt[f[x]]-2,cnt[x]});
            r1[i-1]=max(r1[i-1],cnt[x]);
            if(lst!=x) r1[i]=max(r1[i],cnt[x]);
            lst=x;
        }
    }
    for(int i=1;i<=n;i++)
        r1[0]=max(r1[0],(int)e[i].size()+1);
    for(int i=n;i>=0;i--){
        r1[i]=max({r1[i],r1[i+1],1});
        r2[i]=max({r2[i],r2[i+1],1});
    } 
    for(int i=1;i<=n;i++) cout<<(i&1?r1[i/2]:r2[i/2])<<' ';
    return 0;
}