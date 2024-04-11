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
#define taskname "G"
int n;
int a[200001];
int cnt;
vector <int> vertices;
int f[200001];
int done[200001];
bool out[200001];
vector <int> g[200001];
void visit(int u){
    done[u]=cnt;
    vertices.pb(u);
    f[u]=1;
    for(int v: g[u]) if(!out[v]) if(done[v]!=cnt){
        visit(v);
        f[u]+=f[v];
    }
}
ll c[200001];
int temp[200001];
vector <int> d[200001];
vector <int> w;
int nroot;
void dfs(int u, int x){
    done[u]=cnt;
    x=__gcd(a[u], x);
    c[x]++;
    if(u==nroot) for(int v: d[a[u]]) temp[v]=0;
    else{
        w.pb(x);
        for(int v: d[a[nroot]]) if(temp[v]) c[__gcd(x, v)]+=temp[v];
    }
    for(int v: g[u]) if(!out[v]) if(done[v]!=cnt){
        dfs(v, x);
        if(u==nroot){
            for(int a: w) temp[a]++;
            w.clear();
        }
    }
}
void centroid(int u, int level){
    if(level>30){
        exit(-1);
    }
    cnt++;
    vertices.clear();
    visit(u);
    int root=u, best=n+1;
    for(int u: vertices){
        int r=vertices.size()-f[u];
        for(int v: g[u]) if(done[v]==cnt) if(f[v]<f[u]){
            r=max(r, f[v]);
        }
        if(r<best){
            root=u;
            best=r;
        }
    }
    cnt++;
    nroot=root;
    dfs(root, 0);
    out[root]=1;
    for(int v: g[root]) if(!out[v]) centroid(v, level+1);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    FOR(i, 1, 200000) for(int j=i; j<=200000; j+=i) d[j].pb(i);
    read(n);
    FOR(i, 1, n) read(a[i]);
    {
        int u, v;
        FFOR(i, 1, n){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    centroid(1, 0);
    FOR(i, 1, 200000) if(c[i]){
        write(i);
        putchar(' ');
        writeln(c[i]);
    }
}