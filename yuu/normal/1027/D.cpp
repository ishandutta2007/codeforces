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
#define taskname "D"
int n;
int a[200001];
int c[200001];
vector <int> g[200001];
int ans;
int res;
int done[200001];
vector <int> s;
int cnt=0;
int num[200001];
int low[200001];
int from[200001];
int root[200001];
vector <int> cc[200001];
int ccnt=0;
void dfs(int u){
    done[u]=1;
    cnt++;
    num[u]=low[u]=cnt;
    s.pb(u);
    if(!done[a[u]]){
        dfs(a[u]);
        low[u]=min(low[u], low[a[u]]);
    }
    else if(done[a[u]]==1) low[u]=min(low[u], num[a[u]]);
    if(low[u]==num[u]){
        ccnt++;
        int v;
        do{
            v=s.back();
            s.pop_back();
            from[v]=ccnt;
            cc[ccnt].pb(v);
        }
        while(v!=u);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(c[i]);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) if(!done[i]) dfs(i);
    FOR(i, 1, ccnt){
        root[i]=1;
        for(int u: cc[i]) if(from[a[u]]!=i) root[i]=0;
    }
    FOR(i, 1, ccnt) if(root[i]){
        res=1e9;
        for(int v: cc[i]) res=min(res, c[v]);
        ans+=res;
    }
    writeln(ans);
}