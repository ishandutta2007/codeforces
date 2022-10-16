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
#define taskname "C"
int n, m;
struct edge{
    int u, v;
    char c;
} e[100001];
int r[200001];
int co[200001];
bool isroot[200001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void uni(int u, int v){
    u=root(u); v=root(v);
    if(u==v) return;
    if(r[u]>r[v]) swap(u, v);
    r[u]+=r[v];
    r[v]=u;
}
bool f[200001];
bool done[200001];
vector <int> g[200001];
vector <int> ans, res;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    cin>>n>>m;
    FOR(i, 1, m){
        cin>>e[i].u>>e[i].v>>e[i].c;
        e[i].c=e[i].c=='R';
    }
    bool good=0;
    FOR(c, 0, 1){
        res.clear();
        FOR(i, 1, n+n) r[i]=-1;
        FOR(i, 1, m) if(e[i].c==c){
            uni(e[i].u, e[i].v);
            uni(e[i].u+n, e[i].v+n);
        }
        else{
            uni(e[i].u, e[i].v+n);
            uni(e[i].u+n, e[i].v);
        }
        FOR(i, 1, n) if(root(i)==root(i+n)) goto line1;
        FOR(i, 1, n+n) g[i].clear();
        FOR(i, 1, n+n) g[root(i)].pb(i);
        FOR(i, 1, n+n) f[i]=done[i]=0;
        FOR(i, 1, n) if(!done[i]){
            int r=root(i);
            int d=0;
            for(int x: g[r]){
                done[x]=1;
                if(x>n) done[x-n]=1;
                else d++;
            }
            if(d>g[r].size()-d) r=root(i+n);
            for(int x: g[r]) if(x<=n) res.pb(x);
        }
        if(!good){
            ans=res;
            good=1;
        }
        else if(ans.size()>res.size()){
            ans=res;
        }
        line1:;
    }
    if(!good) puts("-1");
    else{
        writeln(ans.size());
        for(int x: ans){
            write(x);
            putchar(' ');
        }
    }

}