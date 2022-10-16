#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "161D"
int n, k;
int done[50001];
bool out[50001];
int child[50001];
vector <int> g[50001];
int t;
void visit(int u){
    done[u]=t;
    child[u]=1;
    for(int v: g[u]) if(!out[v]) if(done[v]!=t){
        visit(v);
        child[u]+=child[v];
    }
}
int cnt[501];
vector <int> upd;
ll ans=0;
int all;
void dfs(int u, int h){
    done[u]=t;
    if(h>k) return;
    if(h){
        upd.pb(h);
        ans+=cnt[k-h];
    }
    else cnt[0]++;
    for(int v: g[u]) if(!out[v]) if(done[v]!=t){
        dfs(v, h+1);
        if(h==0){
            for(auto x: upd) cnt[x]++;
            upd.clear();
        }
    }
}
void centroid(int u){
    t++;
    visit(u);
    all=child[u];
    while(true){
        int nx=-1;
        for(int v: g[u]) if(done[v]==t) if(child[v]<child[u]) if(child[v]*2>all){
            nx=v;
            break;
        }
        if(nx==-1) break;
        u=nx;
    }
    t++;
    FOR(i, 0, k) cnt[i]=0;
    dfs(u, 0);
    out[u]=1;
    for(int v: g[u]) if(!out[v]) centroid(v);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    {
        int a, b;
        FFOR(i, 1, n){
            read(a);
            read(b);
            g[a].pb(b);
            g[b].pb(a);
        }
    }
    centroid(1);
    writeln(ans);
}