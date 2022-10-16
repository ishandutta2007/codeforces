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
int n, m;
vector <pair <int, ll> > g[200001];
ll a[200001];
ll f[200001];
const ll inf=mask(60);
struct cmp{
    bool operator ()(pair <int, ll> a, pair <int, ll> b){
        return a.second>b.second;
    }
};
priority_queue <pair <int, ll>, vector <pair <int, ll> >, cmp> q;
void dij(){
    FOR(i, 1, n) f[i]=inf;
    q.push(mp(0, 0));
    pair <int, ll> p;
    while(!q.empty()){
        p=q.top();
        q.pop();
        if(p.second>f[p.first]) continue;
        for(pair <int, ll> v: g[p.first]){
            if(f[v.first]>f[p.first]+v.second){
                f[v.first]=f[p.first]+v.second;
                q.push(mp(v.first, f[v.first]));
            }
        }
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    {
        int u, v;
        ll w;
        FOR(i, 1, m){
            read(u);
            read(v);
            read(w);
            w*=2;
            g[u].pb(mp(v, w));
            g[v].pb(mp(u, w));
        }
    }
    FOR(i, 1, n){
        read(a[i]);
        g[0].pb(mp(i, a[i]));
    }
    dij();
    FOR(i, 1, n){
        write(f[i]);
        putchar(' ');
    }
}