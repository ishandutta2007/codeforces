#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "C"
int n, m, q;
struct dq{
    int c[10];
    int sz;
    void push_back(int x){
        c[sz]=x;
        sz++;
    }
} f[100001][18], k[100001];
int p[100001][18];
int depth[100001];
vector <int> g[100001];
dq join(dq &A, dq &B){
    int i=0, j=0;
    dq res;
    res.sz=0;
    while(!(i==A.sz&&j==B.sz)){
        if(i==A.sz){
            res.pb(B.c[j]);
            j++;
        }
        else if(j==B.sz){
            res.pb(A.c[i]);
            i++;
        }
        else if(A.c[i]<B.c[j]){
            res.pb(A.c[i]);
            i++;
        }
        else{
            res.pb(B.c[j]);
            j++;
        }
        if(res.sz==10) return res;
    }
    return res;
}
void dfs(int u){
    for(int i=0; p[p[u][i]][i]; i++){
        p[u][i+1]=p[p[u][i]][i];
        f[u][i+1]=join(f[u][i], f[p[u][i]][i]);
    }
    for(int v: g[u]) if(v!=p[u][0]){
        depth[v]=depth[u]+1;
        f[v][0]=k[u];
        p[v][0]=u;
        dfs(v);
    }
}
void query(int u, int v, int a){
    if(depth[u]<depth[v]) swap(u, v);
    dq res=k[u];
    int i=17;
    if(u==v) goto line1;
    while(i>=0){
        if(depth[p[u][i]]>=depth[v]){
            res=join(res, f[u][i]);
            u=p[u][i];
        }
        i--;
    }
    if(u==v) goto line1;
    res=join(res, k[v]);
    i=17;
    while(i>=0){
        if(p[u][i]!=p[v][i]){
            res=join(res, f[u][i]);
            res=join(res, f[v][i]);
            u=p[u][i];
            v=p[v][i];
        }
        i--;
    }
    res=join(res, k[p[u][0]]);
    line1:;
    a=min(a, res.sz);
    write(a);
    a--;
    FOR(i, 0, a){
        putchar(' ');
        write(res.c[i]);
    }
    putchar('\n');
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    read(q);
    int u, v, a;
    FOR(i, 2, n){
        read(u);
        read(v);
        g[u].pb(v);
        g[v].pb(u);
    }
    FOR(i, 1, m){
        int c;
        read(c);
        if(k[c].sz<10) k[c].pb(i);
    }
    depth[1]=1;
    dfs(1);
    FOR(i, 1, q){
        read(u);
        read(v);
        read(a);
        query(u, v, a);
    }
}