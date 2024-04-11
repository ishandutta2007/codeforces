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
#define taskname "C"
int n;
int m;
class word{
public:
    int l;
    vector <int> v;
    void input(){
        read(l);
        v.resize(l);
        for(int &x: v) read(x);
    }
} w[100001];
int _not[200001];
vector <int> g[200001];
void link(int a, int b){
    if(a<b){
        g[_not[b]].pb(_not[a]);
        g[a].pb(b);
    }
    else{
        g[a].pb(_not[a]);
        g[_not[a]].pb(b);
        g[_not[b]].pb(b);
    }
}
void make(int l, int r, int d){
    while((l<=r)&&(w[l].v.size()==d)) l++;
    if(l>=r) return;
    FOR(i, l, r){
        int j=i;
        while(j<r){
            if(w[j+1].l<=d){
                puts("No");
                exit(0);
            }
            if(w[j+1].v[d]==w[i].v[d]) j++;
            else break;
        }
        make(i, j, d+1);
        if(j<r) link(w[j].v[d], w[j+1].v[d]);
        i=j;
    }
}
int done[200001];
int cnt;
int num[200001];
int low[200001];
int ccnt;
vector <int> s;
int from[200001];
void dfs(int u){
    cnt++;
    done[u]=1;
    num[u]=low[u]=cnt;
    s.pb(u);
    for(int v: g[u]) if(!done[v]){
        dfs(v);
        low[u]=min(low[u], low[v]);
    }
    else if(done[v]==1) low[u]=min(low[u], num[v]);
    if(num[u]==low[u]){
        int v;
        ccnt++;
        while(s.back()!=u){
            v=s.back();
            s.pop_back();
            from[v]=ccnt;
            done[v]=2;
//            connected_component[ccnt].pb(v);
        }
        v=s.back();
        s.pop_back();
        from[v]=ccnt;
        done[v]=2;
//        connected_component[ccnt].pb(v);
    }
}
vector <int> h[200001];
int topo[200001];
int done2[200001];
int tpc;
void dfs2(int u){
    done2[u]=1;
    for(int v: h[u]) if(!done2[v]) dfs(v);
    topo[u]=tpc;
    tpc--;
}
vector <int> ans;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    FOR(i, 1, n) w[i].input();
    FOR(i, 1, m) _not[i]=i+m;
    FOR(i, 1, m) _not[i+m]=i;
    make(1, n, 0);
    FOR(i, 1, m*2) if(!done[i]) dfs(i);
    FOR(i, 1, m) if(from[i]==from[_not[i]]){
        puts("No");
        exit(0);
    }
    FOR(u, 1, m*2) for(int v: g[u]) if(from[u]!=from[v]) h[from[u]].pb(from[v]);
    tpc=ccnt;
    FOR(u, 1, ccnt) if(!done2[u]) dfs2(u);
    puts("Yes");
    FOR(u, 1, m) if(topo[from[u]]<topo[from[_not[u]]]) ans.pb(u);
    writeln(ans.size());
    for(int x: ans) write(x), putchar(' ');
}