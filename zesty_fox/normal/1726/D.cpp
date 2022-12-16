#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=4e5+10;

int n,m;
struct Edge{int to,nxt,flg;}e[N*2];
int head[N],tot=1;

void add_e(int x,int y){
    e[++tot]={y,head[x],0};head[x]=tot;
}

int vis[N],tofa[N],dep[N];
void dfs(int x){
    vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(vis[y]) continue;
        e[i].flg=e[i^1].flg=1;
        tofa[y]=i,dep[y]=dep[x]+1;
        dfs(y);
    }
}

void clear(){
    tot=1;
    for(int i=1;i<=n;i++) head[i]=vis[i]=tofa[i]=dep[i]=0;
}

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        add_e(x,y),add_e(y,x);
    }
    dfs(1);
    if(m==n+2){
        vi nodes,edges;
        int sum=0;
        for(int i=2;i<=tot;i+=2){
            if(e[i].flg) continue;
            edges.pb(i);
            int x=e[i].to,y=e[i^1].to;
            sum=sum^x^y,nodes.pb(x),nodes.pb(y);
        }
        if(!sum){
            int mx=*max_element(nodes.begin(),nodes.end(),[&](int x,int y){return dep[x]<dep[y];});
            e[tofa[mx]].flg=e[tofa[mx]^1].flg=0;
            for(auto id:edges){
                int x=e[id].to,y=e[id^1].to;
                if(dep[x]<dep[y]) swap(x,y);
                if(mx==x){
                    e[id].flg=e[id^1].flg=1;
                    break;
                }
            }
        }
    }
    for(int i=2;i<=tot;i+=2) putchar(e[i].flg+'0');
    puts("");
    clear();
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