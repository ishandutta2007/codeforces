#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010;

int n,w[N],sum[N];
vi e[N];

void clear(){
    for(int x=1;x<=n;x++) e[x].clear(),w[x]=sum[x]=0;
}

void dfs(int x,int fa,int dep){
    bool flg=1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x,dep+1);
        sum[x]=-sum[y];
        flg=0;
    }
    if(flg) sum[x]=w[x]=(dep&1?-1:1);
    else{
        w[x]=sum[x];
        for(auto y:e[x]) 
            if(y!=fa) w[x]-=sum[y];
        if(x==1){
            w[x]=0;
            for(auto y:e[x]){
                if(y!=fa) w[x]-=sum[y];
            }
        }
    }
}

void solve(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    /*
    int rt=0,mxsiz=0;
    for(int x=1;x<=n;x++){
        int cnt=0;
        for(auto y:e[x])
            cnt+=(e[y].size()>1);
        if(cnt<=1){
            if(e[x].size()>mxsiz) mxsiz=e[x].size(),rt=x;
        }
    }
    int to=0,cnt=0;
    for(auto y:e[rt]){
        if(e[y].size()<=1) w[y]=-1,cnt++;
        else to=y;
    }
    w[rt]=-cnt-1;
    sum[to]=1;dfs(to,rt,-1);*/
    dfs(1,0,0);
    for(int i=1;i<=n;i++) cout<<w[i]<<' ';
    cout<<'\n';clear();
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}