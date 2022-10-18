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
ll f[10];
deque <ll> w[4];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FFOR(i, 0, 10) f[i]=-1e18;
    f[1]=0;
    FOR(i, 1, n){
        ll g[10];
        FFOR(x, 0, 10) g[x]=f[x];
        FOR(x, 1, 3) w[x].clear();
        FOR(x, 1, 3) w[1].pb(-1e18);
        FOR(x, 2, 3) w[x].pb(-1e18);
        ll d;
        int c, k;
        read(k);
        FOR(j, 1, k){
            read(c);
            read(d);
            w[c].pb(d);
            sort(w[c].begin(), w[c].end());
            w[c].pop_front();
        }
        ///1
        {
            ll mx=-1e18;
            FOR(x, 1, 3) if(w[x].back()>mx) mx=w[x].back();
            FFOR(j, 0, 10) g[(j+1)%10]=max(g[(j+1)%10], f[j]+mx+mx*(ll(j==0)));
        }
        ///2
        {
            ll x=w[1][2];
            ll y=max(w[2].back(), w[1][1]);
            ll mx=max(x, y);
            FFOR(j, 0, 10) g[(j+2)%10]=max(g[(j+2)%10], f[j]+x+y+mx*(ll(j==0))+mx*(ll(j==9)));
        }
        ///3
        {
            ll sum=0;
            ll mx=0;
            for(ll x: w[1]){
                sum+=x;
                if(x>mx) mx=x;
            }
            FFOR(j, 0, 10) g[(j+3)%10]=max(g[(j+3)%10], f[j]+sum+mx*(ll(j==0))+mx*(ll(j==9))+mx*(ll(j==8)));
        }
        FFOR(j, 0, 10) f[j]=g[j];
    }
    ll ans=-1e18;
    FFOR(i, 0, 10) ans=max(ans, f[i]);
    writeln(ans);
}