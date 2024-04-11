#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "F"
int n;
int a[5001];
int cnt[5001];
int all[5001];
ll f[5001][5001];
const ll base=998244353;
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) cnt[a[i]]++;
    DFOR(i, n-1, 1) all[i]=all[i+1]+cnt[i+1];
    cnt[0]=1;
    ll win=0;
    f[0][0]=1;
    FFOR(i, 0, n){
        ll space=power(n-i, base-2);
        ll chance=0;
        FOR(j, 0, n){
            f[i+1][j]=((chance*cnt[j])%base*space)%base;
            if(f[i][j]){
                win=(win+(f[i][j]*(cnt[j]-1))%base*space)%base;
                chance=(chance+f[i][j])%base;
            }
        }
    }
    writeln(win);
}