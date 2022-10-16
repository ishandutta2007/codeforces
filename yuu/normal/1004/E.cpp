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
#define taskname "E"
int n, k;
vector <pair <int, ll> > g[100001];
vector <pair <int, ll> > c[100001];
int trace[100001];
bool done[100001];
ll f[100001];
class cmp{
public:
    bool operator()(pair <int, ll> a, pair <int, ll> b){
        return a.second>b.second;
    }
};
priority_queue <pair <int, ll>, vector <pair <int, ll>>, cmp> q;
int dij(int u){
    while(!q.empty()) q.pop();
    FOR(i, 1, n) f[i]=1e18;
    f[u]=0;
    trace[u]=-1;
    q.push(mp(u, 0));
    int res=0;
    while(!q.empty()){
        pair <int, ll> p=q.top();
        q.pop();
        if(p.second>f[p.first]) continue;
        res=p.first;
        for(pair <int, ll> v: g[p.first]){
            if(f[v.first]>f[p.first]+v.second){
                f[v.first]=f[p.first]+v.second;
                trace[v.first]=p.first;
                q.push(mp(v.first, f[v.first]));
            }
        }
    }

    return res;
}
ll ans=1e18;
vector <int> path;
ll d[100001];
void dfs(int u){
    done[u]=1;
    d[u]=0;
    for(pair <int, ll> v: g[u]) if(!done[v.first]){
        dfs(v.first);
        d[u]=max(d[u], d[v.first]+v.second);
        c[u].pb(v);
    }
    sort(c[u].begin(), c[u].end(), [](pair <int, ll> A, pair <int, ll> B){
        return d[A.first]+A.second>d[B.first]+B.second;
    });
}
ll down(int &x){
    ll res=0;
    FFOR(i, 1, c[x].size()) res=max(res, d[c[x][i].first]+c[x][i].second);
    x=c[x][0].first;
    return res;
}
void check(int u){///check all path contain u
    FOR(i, 1, n) c[i].clear();
    FOR(i, 1, n) done[i]=0;
    dfs(u);
    ans=min(ans, d[u]);
    if(k>1){
        ll best=0;
        FFOR(i, 1, c[u].size()) best=max(best, d[c[u][i].first]+c[u][i].second);
        int x=c[u][0].first;
        FOR(i, 3, k){
            if(c[x].empty()) break;
            best=max(best, down(x));
        }
        best=max(best, d[x]);
        ans=min(ans, best);
    }
    if(k>2){
        ll best=0;
        FFOR(i, 2, c[u].size()) best=max(best, d[c[u][i].first]+c[u][i].second);
        int x=c[u][0].first;
        int y=c[u][1].first;
        FOR(i, 4, k){
            if(c[x].empty()&&c[y].empty()) break;
            if((d[x]>d[y])||(c[y].empty())){
                best=max(best, down(x));
            }
            else best=max(best, down(y));
        }
        best=max(best, d[x]);
        best=max(best, d[y]);
        ans=min(ans, best);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    if(n==1){
        writeln(0);
        return 0;
    }
    {
        int u, v, d;
        FFOR(i, 1, n){
            read(u);
            read(v);
            read(d);
            g[u].pb(mp(v, d));
            g[v].pb(mp(u, d));
        }
    }
    if(n==2){
        if(k==2) writeln(0);
        else writeln(g[1][0].second);
        return 0;
    }
    int u=dij(1);
    int v=dij(u);
    while(v!=-1){
        path.pb(v);
        v=trace[v];
    }
    reverse(path.begin(), path.end());
    int i=0;
    while((i<path.size())&&(f[path[i]]<f[path.back()]-f[path[i]])) i++;
    if(i<path.size()) check(path[i]);
    if(i-1>0) check(path[i-1]);
    writeln(ans);
}