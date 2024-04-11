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
#define taskname "E"
#define time adtra
int n;
vector <int> g[4][4];
int single[4];
int ans=0;
int deg[4];
int sum[4][4];
vector <int> h[4];
int cnt=0;
int time=0;
int done[4];
void dfs(int u){
    done[u]=time;
    cnt++;
    for(int v: h[u]) if(done[v]!=time) dfs(v);
}
void solve(vector <int> vertices){
    vector <pair <int, int> > edge;
    int res=-1e9;
    for(int x: vertices) for(int y: vertices) if(x<y) if(!g[x][y].empty()) edge.pb(mp(x, y));
    FFOR(s, 0, mask(edge.size())){
        FFOR(i, 0, 4){
            h[i].clear();
            deg[i]=0;
        }
        FFOR(i, 0, edge.size()){
            deg[edge[i].first]+=g[edge[i].first][edge[i].second].size()-bit(s, i);
            deg[edge[i].second]+=g[edge[i].first][edge[i].second].size()-bit(s, i);
            if(g[edge[i].first][edge[i].second].size()>bit(s, i)){
                h[edge[i].first].pb(edge[i].second);
                h[edge[i].second].pb(edge[i].first);
            }
        }
        int odd=0;
        FFOR(i, 0, 4) odd+=deg[i]%2;
        if(odd>2) continue;
        cnt=0;
        time++;
        dfs(vertices[0]);
        if(cnt<vertices.size()) continue;
        ///good
        int now=0;
        FFOR(i, 0, edge.size()){
            now+=sum[edge[i].first][edge[i].second];
            if(bit(s, i)) now-=g[edge[i].first][edge[i].second][0];
        }
        res=max(res, now);
    }
    for(int u: vertices) res+=single[u];
//    bug(res);
//    for(int u: vertices) cerr<<u<<' ';
//    cerr<<'\n';
    ans=max(ans, res);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    {
        int c0, c1, v;
        FOR(i, 1, n){
            read(c0);
            c0--;
            read(v);
            read(c1);
            c1--;
            if(c0>c1) swap(c0, c1);
            if(c0==c1) single[c0]+=v;
            else{
                g[c0][c1].pb(v);
                g[c1][c0].pb(v);
                sum[c0][c1]+=v;
                sum[c1][c0]+=v;
            }
        }
    }
    FFOR(i, 0, 4) FFOR(j, 0, 4) sort(g[i][j].begin(), g[i][j].end());
    FFOR(s, 0, mask(4)){
        vector <int> v;
        FFOR(i, 0, 4) if(bit(s, i)) v.pb(i);
        if(v.size()) solve(v);
    }
    writeln(ans);

}