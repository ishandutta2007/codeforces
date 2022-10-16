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
int n, m, k;
vector <int> g[300001];
class edge{
public:
    int u, v, c;
    void input(int id){
        read(u);
        read(v);
        read(c);
        g[u].pb(id);
        g[v].pb(id);
    }
    int other(int x){
        return u^v^x;
    }

} e[300001];
class data{
public:
    int u;
    ll c;
    data(int u, ll c){
        this->u=u;
        this->c=c;
    }
};
class cmp{
public:
    bool operator()(data A, data B){
        return A.c>B.c;
    }
};
priority_queue <data, vector<data>, cmp> q;
ll f[300001];
int trace[300001];
void dij(){
    FOR(i, 2, n) f[i]=1e18;
    q.push(data(1, 0));
    while(!q.empty()){
        data d=q.top();
        q.pop();
        if(d.c>f[d.u]) continue;
        for(int i: g[d.u]){
            int v=e[i].other(d.u);
            if(f[v]>f[d.u]+e[i].c){
                f[v]=f[d.u]+e[i].c;
                q.push(data(v, f[v]));
                trace[v]=i;
            }
        }
    }
}
vector <int> ans;
void dfs(int u){
    for(int i: g[u]){
        int v=e[i].other(u);
        ans.pb(i);
        dfs(v);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(k);
    FOR(i, 1, m) e[i].input(i);
    dij();
    FOR(i, 1, n) g[i].clear();
    FOR(i, 2, n){
        int p=e[trace[i]].other(i);
        g[p].pb(trace[i]);
    }
    dfs(1);
    while(ans.size()>k) ans.pop_back();
    writeln(ans.size());
    for(int x: ans){
        write(x);
        putchar(' ');
    }
}