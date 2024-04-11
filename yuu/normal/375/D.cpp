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
#define taskname "375D"
int n, m;
int c[100001];
class data{
public:
    using pointer=data*;
    map <int, int> M;
    vector <int> cnt;
    data(){
        cnt.resize(1);
        M.clear();
    }
    void insert(int x, int feq){
        int nx=M[x]+feq;
        while(cnt.size()<=nx) cnt.pb(0);
        FOR(i, M[x]+1, nx) cnt[i]++;
        M[x]=nx;
    }
    void insert(data &d){
        d.cnt.clear();
        for(auto t: d.M) insert(t.first, t.second);
        d.M.clear();
    }
    int size(){
        return M.size();
    }
};
data::pointer f[100001];
bool done[100001];
vector <int> g[100001];
int ans[100001];
vector <pair <int, int>> q[100001];
void dfs(int u){
    done[u]=1;
    for(int &x: g[u]) if(done[x]){
        swap(x, g[u].back());
        g[u].pop_back();
        break;
    }
    for(int v: g[u]) dfs(v);
    if(g[u].empty()){
        f[u]=new data();
    }
    else{
        sort(g[u].begin(), g[u].end(), [](int a, int b){
            return f[a]->size()<f[b]->size();
        });
        f[u]=f[g[u].back()];
        g[u].pop_back();
        for(int v: g[u]) f[u]->insert(*f[v]);
    }
    f[u]->insert(c[u], 1);
    for(auto p: q[u]) ans[p.second]=(f[u]->cnt.size()>p.first)?f[u]->cnt[p.first]:0;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
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
    {
        int u, v;
        FOR(i, 1, m){
            read(u);
            read(v);
            q[u].pb(mp(v, i));
        }
    }
    dfs(1);
    FOR(i, 1, m) writeln(ans[i]);
}