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
typedef long long ll;
typedef long double ld;
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
#define taskname "E"
vector <int> g[200001];
vector <int> h[200001];
bool done[200001];
int n, m;
int r[200001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void uni(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return;
    h[u].pb(v);
    h[v].pb(u);
    r[u]+=r[v];
    r[v]=u;
}
vector <int> good;
vector <int> boss;
set <int> s;
int dfstime[200001];
vector <int> ans;
int ntime;
bool dfs(int u, int a){
    if(s.find(u)==s.end()){
        uni(u, a);
        return 1;
    }
    dfstime[u]=ntime;
    for(int v: h[u]) if(dfstime[v]!=ntime) if(dfs(v, a)) return 1;
    return 0;
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    FOR(i, 1, n){
        r[i]=-1;
        good.pb(i);
    }
    {
        int u, v;
        FOR(i, 1, m){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    sort(good.begin(), good.end(), [](int a, int b){
        return (g[a].size())<(g[b].size());
    });
    boss.pb(good[0]);
    done[good[0]]=1;
    for(int v: g[boss.back()]) s.insert(v);
    FOR(i, 1, n) if(s.find(i)==s.end()){
        uni(boss.back(), i);
        done[i]=1;
    }
    for(int u: good){
        if(done[u]) continue;
        s.clear();
        for(int v: g[u]) s.insert(v);
        for(int v: boss){
            int a=root(v);
            if((-r[a])>((int)g[u].size())){
                uni(u, v);
                done[u]=1;
            }
            else{
                ntime++;
                if(dfs(v, u)) done[u]=1;
            }
        }
        if(!done[u]){
            boss.pb(u);
            FOR(i, 1, n) if(s.find(i)==s.end()){
                uni(boss.back(), i);
            }
        }
    }
    s.clear();
    for(int i: boss) if(s.find(root(i))==s.end()){
        s.insert(root(i));
        ans.pb(-r[root(i)]);
    }
    sort(ans.begin(), ans.end());
    writeln(ans.size());
    for(int x: ans) write(x), putchar(' ');
}