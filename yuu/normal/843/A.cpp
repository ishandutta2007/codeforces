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
#define taskname "A"
int n;
int a[100001];
int b[100001];
vector <int> g[100001];
vector <int> c[100001];
bool done[100001];
int ans=0;
void dfs(int u){
    done[u]=1;
    c[ans].pb(u);
    for(int v: g[u]) if(!done[v]) dfs(v);
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    FOR(i, 1, n){
        read(a[i]);
        b[i]=a[i];
    }
    sort(b+1, b+n+1);
    FOR(i, 1, n) a[i]=lower_bound(b+1, b+n+1, a[i])-b;
    FOR(i, 1, n) g[a[i]].pb(i);
    FOR(i, 1, n) if(!done[i]){
        ans++;
        dfs(i);
    }
    writeln(ans);
    FOR(i, 1, ans){
        write(c[i].size());
        for(int v: c[i]){
            putchar(' ');
            write(v);
        }
        putchar('\n');
    }
}