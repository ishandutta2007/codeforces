#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;
const int INF=0x3f3f3f3f;

int n1,n2,m,q;

namespace MF{
    struct Edge{int to,nxt,f;}e[N*8];
    int head[N*2],tot=1;
    void add_e(int x,int y,int f){
        e[++tot]={y,head[x],f},head[x]=tot;
        e[++tot]={x,head[y],0},head[y]=tot;
    }
    int dep[N*2],cur[N*2];
    bool bfs(int n,int S,int T){
        for(int i=1;i<=n;i++)
            dep[i]=0,cur[i]=head[i];
        queue<int> q;
        dep[S]=1,q.push(S);
        while(!q.empty()){
            int x=q.front();q.pop();
            if(x==T) return true;
            for(int i=head[x];i;i=e[i].nxt){
                int y=e[i].to;
                if(e[i].f&&!dep[y])
                    dep[y]=dep[x]+1,q.push(y);
            }
        }
        return false;
    }
    int dfs(int x,int T,int fl){
        if(x==T) return fl;
        int rest=fl;
        for(int &i=cur[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(e[i].f&&dep[y]==dep[x]+1){
                int lim=min(rest,e[i].f);
                int tmp=dfs(y,T,lim);
                if(tmp<lim) dep[y]=0;
                e[i].f-=tmp,e[i^1].f+=tmp,rest-=tmp;
                if(!rest) break;
            }
        }
        return fl-rest;
    }
    int mf(int n,int S,int T){
        int ret=0;
        while(bfs(n,S,T)) ret+=dfs(S,T,INF);
        return ret;
    }
    vi get_mvc(int n1,int n2,int S,int T){
        mf(n1+n2+2,S,T);
        static int vis[N*2];
        auto dfs = [&](auto &&self,int x)->void{
            vis[x]=1;
            for(int i=head[x];i;i=e[i].nxt){
                int y=e[i].to;
                if(vis[y]||y==S||y==T) continue;
                if(e[i].f) self(self,y);
            }
        };
        for(int i=head[S];i;i=e[i].nxt){
            int y=e[i].to;
            if(e[i].f) dfs(dfs,y);
        }
        vi ret;
        for(int i=1;i<=n1;i++)
            if(!vis[i]) ret.pb(i);
        for(int i=1;i<=n2;i++)
            if(vis[i+n1]) ret.pb(i+n1);
        return ret;
    }
}

int S,T,num;
void init(){
    n1=rdi(),n2=rdi(),m=rdi(),q=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        MF::add_e(x,y+n1,1);
    }
    S=n1+n2+1,T=n1+n2+2;
    for(int i=1;i<=n1;i++) MF::add_e(S,i,1);
    for(int i=1;i<=n2;i++) MF::add_e(i+n1,T,1);
}

void solve(){
    vi cur=MF::get_mvc(n1,n2,S,T);
    i64 sum_id=0;set<int> id;
    for(int i=1;i<=m;i++)
        if(!MF::e[i*2].f) sum_id+=i,id.insert(i);
    while(q--){
        int op=rdi();
        if(op==1){
            int x=cur.back();cur.pop_back();
            for(int i=MF::head[x];i;i=MF::e[i].nxt){
                int y=MF::e[i].to,f=MF::e[i].f;
                if(y==S||y==T) continue;
                if((x<=n1)^f){
                    sum_id-=i/2,id.erase(i/2);
                    break;
                }
            }
            cout<<1<<'\n'<<(x<=n1?x:-(x-n1))<<'\n'<<sum_id<<'\n'<<flush;
        }
        else{
            cout<<id.size()<<'\n';
            for(auto i:id) cout<<i<<' ';
            cout<<'\n'<<flush;
        }
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init();solve();
    return 0;
}