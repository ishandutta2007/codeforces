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
vector <int> d[200001];
vector <int> g[200001];
vector <int> v;
int gcd[200001][21];
int f[200001][21];
int h[200001];
int a[200001];
int ans[200001];
bool done[200001];
int n;
void dfs(int u){
    done[u]=1;
    for(int i=0; f[f[u][i]][i]; i++){
        f[u][i+1]=f[f[u][i]][i];
        gcd[u][i+1]=__gcd(gcd[u][i], gcd[f[u][i]][i]);
    }
    FFOR(i, 0, g[u].size()) if(!done[g[u][i]]){
        f[g[u][i]][0]=u;
        gcd[g[u][i]][0]=__gcd(a[g[u][i]], a[u]);
        h[g[u][i]]=h[u]+1;
        dfs(g[u][i]);
    }
    else{
        swap(g[u][i], g[u].back());
        g[u].pop_back();
        i--;
    }
}
void cal(int u){
    if(u==1) ans[u]=a[u];
    else{
        ans[u]=max(ans[u], v[v.size()-2]);
        for(int x: d[a[u]]){
            int uu=u;
            int i=20;
            while(i>=0){
                if(f[uu][i]&&gcd[uu][i]%x==0) uu=f[uu][i];
                i--;
            }
            if(uu==1||h[uu]==1) ans[u]=max(ans[u], x);
            else{
                ans[u]=max(ans[u], __gcd(v[h[uu]-2], x));
            }
            if(ans[u]==x) break;
        }
    }
    for(int x: g[u]){
        v.pb(__gcd(v.back(), a[x]));
        cal(x);
        v.pop_back();
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    FOR(i, 1, 200000){
        for(int j=i; j<=200000; j+=i) d[j].pb(i);
    }
    FOR(i, 1, 200000) reverse(d[i].begin(), d[i].end());
    read(n);
    FOR(i, 1, n) read(a[i]);
    FFOR(i, 1, n){
        int u, v;
        read(u);
        read(v);
        g[u].pb(v);
        g[v].pb(u);
    }
    v.pb(a[1]);
    dfs(1);
    cal(1);
    FOR(i, 1, n) write(ans[i]), putchar(' ');
}