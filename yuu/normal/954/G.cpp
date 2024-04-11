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
#define taskname "G"
int n, r;
ll k;
ll a[500001];
ll s[500001];
ll b[500001];
ll p[500001];
ll f[500001];
vector <pair <int, ll> > g[500001];
int low, high;
deque <int> q;
bool check(ll h){
    FOR(i, 1, n) p[i]=h-b[i];
    q.clear();
    FOR(i, low, high) g[i].clear();
    FOR(i, 1, n) if(p[i]>0) g[min(high, i+r)].pb(mp(max(0, i-r-1), p[i]));
    FOR(i, low, high){
        f[i]=f[i-1];
        for(pair <int, ll> p: g[i]) f[i]=max(f[i], f[p.first]+p.second);
    }
    return f[high]<=k;
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(r);
    read(k);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) s[i]=(s[i-1]+a[i]);
    FOR(i, 1, n) b[i]=s[min(n, i+r)]-s[max(0, i-r-1)];
    if(r>=n/2){
        FOR(i, 1, n) b[i]+=k;
        ll ans=b[1];
        FOR(i, 1, n) ans=min(ans, b[i]);
        writeln(ans);
        return 0;
    }
    low=1+r;
    high=n-r;
    ll L=0, R=2e18, M, ans;
    while(L<=R){
        M=(L+R)/2;
        if(check(M)){
            ans=M;
            L=M+1;
        }
        else R=M-1;
    }
    writeln(ans);
}