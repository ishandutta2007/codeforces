#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "B"
struct cmp{
    bool operator () (pair <int, ll> a, pair <int, ll> b){
        return a.second>b.second;
    }
};
priority_queue <pair <int, ll>, vector <pair<int, ll> >, cmp> q;
ll f[100001];
const ll inf = 100000000000000LL;
vector <pair <int, int> > g[100001];
int a[100001];
bool done[100001];
int n, m, k;
void ijk(){
    FOR(i, 1, n)
        f[i]=inf;
    FOR(i, 1, k){
        f[a[i]]=0;
        q.push(mp(a[i], 0));
    }
    while(!q.empty()){
        pair <int, ll> p=q.top();
        q.pop();
        if(p.second>f[p.first]) continue;
        done[p.first]=1;
        for(pair <int, int> v: g[p.first]){
            if(done[v.first]) continue;
            if(f[v.first]<=p.second+v.second) continue;
            f[v.first]=p.second+v.second;
            q.push(mp(v.first, f[v.first]));
        }
    }
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    read(k);
    {
        int u, v, l;
        FOR(i, 1, m){
            read(u);
            read(v);
            read(l);
            g[u].pb(mp(v, l));
            g[v].pb(mp(u, l));
        }
    }
    FOR(i, 1, k)
        read(a[i]);
    ijk();
    ll ans=inf;
    FOR(i, 1, n)
        if(f[i])
            ans=min(ans, f[i]);
    if(ans==inf)
        write(-1);
    else write(ans);
}