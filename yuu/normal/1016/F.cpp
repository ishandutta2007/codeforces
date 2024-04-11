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
#define taskname "F"
int n, m;
vector <pair <int, ll> > g[300001];
bool done[300001];
bool sp[300001];
ll d0[300001];
ll d1[300001];
vector <int> path;
void dfs0(ll u){
    done[u]=1;
    if(u==n) sp[u]=1;
    for(pair <int, ll> v: g[u]) if(!done[v.first]){
        d0[v.first]=d0[u]+v.second;
        dfs0(v.first);
        sp[u]=sp[u]||sp[v.first];
    }
    if(sp[u]) path.pb(u);
}
void dfs1(ll u){
    done[u]=1;
    for(pair <int, ll> v: g[u]) if(!done[v.first]){
        d1[v.first]=d1[u]+v.second;
        dfs1(v.first);
    }
}
ll res=0;
ll expand0(int u){
    ll res=d0[u];
    done[u]=1;
    for(pair <int, ll> v: g[u]) if(!sp[v.first]) if(!done[v.first]) res=max(res, expand0(v.first));
    return res;
}
ll expand1(int u){
    ll res=d1[u];
    done[u]=1;
    for(pair <int, ll> v: g[u]) if(!sp[v.first]) if(!done[v.first]) res=max(res, expand1(v.first));
    return res;
}
bool expand(int u){
    int deg=0;
    done[u]=1;
    bool d=0;
    for(pair <int, ll> v: g[u]) if(!sp[v.first]){
        if(u==1&&v.first==n) continue;
        if(u==n&&v.first==1) continue;
        deg++;
        if((v.first==1)||(v.first==n)){
            if(d==1) deg--;
            d=1;
        }
    }
    if(deg>1) return 1;
    for(pair <int, ll> v: g[u]) if(!sp[v.first]) if(!done[v.first]) return expand(v.first);
    return 0;
}
vector <ll> good;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    {
        ll u, v, w;
        FFOR(i, 1, n){
            read(u);
            read(v);
            read(w);
            g[u].pb(mp(v, w));
            g[v].pb(mp(u, w));
        }
    }
    dfs0(1);
    FOR(i, 1, n) done[i]=0;
    dfs1(n);
    FOR(i, 1, n) done[i]=0;
    sp[1]=sp[n]=0;
    bool alwaybest=expand(1)||expand(n);
    if(alwaybest) res=1e18;
    else{
        sp[1]=sp[n]=1;
        path.pb(0);
        reverse(path.begin(), path.end());
        good.pb(-1e18);
        FOR(i, 1, n) done[i]=0;
        FFOR(i, 1, path.size()){
            good.pb(good[i-1]);
            if(i>1) good.back()=max(good.back(), d0[path[i-1]]);
            for(pair <int, ll> v: g[path[i]]) if(!sp[v.first]) good.back()=max(good.back(), expand0(v.first));
        }
        ll best=-1e18;
        FOR(i, 1, n) done[i]=0;
        DFOR(i, path.size()-1, 2){
            for(pair <int, ll> v: g[path[i]]) if(!sp[v.first]) best=max(best, expand1(v.first));
            res=max(res, best+max(good[i-1], d0[path[i-1]]));
            best=max(best, d1[path[i]]);
            res=max(res, best+good[i-1]);
        }
    }
    {
        ll x;
        FOR(i, 1, m){
            read(x);
            writeln(min(d0[n], x+res));
        }
    }
}