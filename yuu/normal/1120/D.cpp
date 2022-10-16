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
#define taskname "1120D"
int n;
ll c[200001];
vector <int> g[200001];
bool done[200001];
void dfs(int u){
    done[u]=1;
    for(int &v: g[u]) if(done[v]){
        swap(v, g[u].back());
        g[u].pop_back();
        break;
    }
    for(int v: g[u]) dfs(v);
}
ll f[200001][2];
void dp(int u){
    if(g[u].empty()){
        f[u][0]=0;
        f[u][1]=c[u];
    }
    else{
        for(int v: g[u]) dp(v);
        ll total=0;
        for(int v: g[u]) total+=f[v][1];
        f[u][1]=total;
        f[u][0]=total;
        for(int v: g[u]) f[u][0]=min(f[u][0], total-f[v][1]+f[v][0]);
        f[u][1]=min(f[u][1], f[u][0]+c[u]);
        if(g[u].size()==1) f[u][1]=min(f[u][1], f[g[u][0]][1]);
    }
}
bool fn[200001][2];
bool good[200001];
void mark(int u, int b){
    if(fn[u][b]) return;
    fn[u][b]=1;
    ll total=0;
    int cnt=0;
    for(int v: g[u]) total+=f[v][1];
    if(b==0){
        for(int v: g[u]) if(total-f[v][1]+f[v][0]==f[u][0]){
            mark(v, 0);
            cnt++;
            if(cnt<=2) for(int x: g[u]) if(x!=v) mark(x, 1);
        }
    }
    else{
        if(f[u][1]==f[u][0]+c[u]) good[u]=1;
        if(f[u][1]==total) for(int x: g[u]) mark(x, 1);
        for(int v: g[u]) if(total-f[v][1]+f[v][0]+c[u]==f[u][1]){
            mark(v, 0);
            cnt++;
            if(cnt<=2) for(int x: g[u]) if(x!=v) mark(x, 1);
        }
        if(g[u].size()==1) if(f[u][1]==f[g[u][0]][1]) mark(g[u][0], 1);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(c[i]);
    {
        int u, v;
        FFOR(i, 1, n){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    dfs(1);
    dp(1);
    mark(1, 1);
    int k=0;
    FOR(i, 1, n) k+=good[i];
    write(f[1][1]);
    putchar(' ');
    writeln(k);
    FOR(i, 1, n) if(good[i]){
        write(i);
        putchar(' ');
    }
    putchar('\n');
}