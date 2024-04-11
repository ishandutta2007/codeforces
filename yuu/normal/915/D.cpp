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
#define taskname "D"
int n, m;
vector <int> g[501];
int done[501];
int cnt;
int low[501];
int num[501];
vector <int> temp;
vector <int> s;
bool bad[501][501];
bool dfs(int u){
    cnt++;
    done[u]=1;
    num[u]=low[u]=cnt;
    s.pb(u);
    for(int v: g[u]) if(!bad[u][v]){
        if(!done[v]){
            if(dfs(v)) return 1;
            low[u]=min(low[u], low[v]);
        }
        else if(done[v]==1) low[u]=min(low[u], num[v]);
    }
    if(low[u]==num[u]){
        temp.clear();
        while(s.back()!=u){
            temp.pb(s.back());
            done[s.back()]=2;
            s.pop_back();
        }
        temp.pb(s.back());
        done[s.back()]=2;
        s.pop_back();
        if(temp.size()>1) return 1;
    }
    return 0;
}
int c[501][501];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    {
        int u, v;
        FOR(i, 1, m){
            read(u);
            read(v);
            g[u].pb(v);
            c[u][v]=1;
        }
    }
    FOR(i, 1, n) if(!done[i]){
        if(dfs(i)) break;
    }
    vector <int> cycle=temp;
    reverse(cycle.begin(), cycle.end());
    FFOR(i, 0, cycle.size()){
        if(c[cycle[i]][cycle[0]]){
            while(cycle.size()>i+1) cycle.pop_back();
            break;
        }
    }
    cycle.pb(cycle[0]);
    FFOR(i, 1, cycle.size()){
        bad[cycle[i-1]][cycle[i]]=1;
        FOR(i, 1, n) done[i]=0;
        s.clear();
        FOR(i, 1, n) if(!done[i]) if(dfs(i)) goto line0;
        puts("YES");
        return 0;
        line0:;
        bad[cycle[i-1]][cycle[i]]=0;
    }
    puts("NO");
}