#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
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
#define taskname "D"
int n, q, p;
bool done[100001];
int d[100001];
int b[200001];
int l[100001];
int r[100001];
int f[200001][20];
int cnt;
vector <int> g[100001];
void dfs(int u){
    done[u]=1;
    b[++cnt]=u;
    l[u]=cnt;
    r[u]=cnt;
    for(int v: g[u]) if(!done[v]){
        d[v]=d[u]+1;
        dfs(v);
        b[++cnt]=u;
        r[u]=cnt;
    }
}
void make(){
    FOR(i, 1, cnt) f[i][0]=b[i];
    for(int j=1, base=1; (base<<1)<=cnt; j++, base<<=1){
        for(int i=1; i+(base<<1)-1<=cnt; i++){
            if(d[f[i][j-1]]<=d[f[i+base][j-1]]) f[i][j]=f[i][j-1];
            else f[i][j]=f[i+base][j-1];
        }
    }
}
int lca(int u, int v){
    int left=min(l[u], l[v]);
    int right=max(r[u], r[v]);
    int a=__lg(right-left+1);
    int b1=f[left][a];
    int b2=f[right-(1<<a)+1][a];
    if(d[b1]<=d[b2]) return b1;
    return b2;
}
int first(int u, int v, int r){
    int uv=lca(u, v);
    int ur=lca(r, u);
    int vr=lca(r, v);
    if(lca(r, uv)!=uv)
        return uv;
    else{
        if(vr==uv&&uv==ur)
            return uv;
        else{
            if(ur!=uv)
                return ur;
            else return vr;
        }
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(q);
    FOR(i, 2, n){
        read(p);
        g[i].pb(p);
        g[p].pb(i);
    }
    d[1]=1;
    dfs(1);
    make();
    int a, b, c;
    FOR(i, 1, q){
        read(a);
        read(b);
        read(c);
        int ans=0;
        int res=first(a, b, c);
        ans=max(ans, d[c]+d[res]-2*d[lca(c, res)]);
        res=first(a, c, b);
        ans=max(ans, d[b]+d[res]-2*d[lca(b, res)]);
        res=first(b, c, a);
        ans=max(ans, d[a]+d[res]-2*d[lca(a, res)]);
        writeln(ans+1);
    }
}