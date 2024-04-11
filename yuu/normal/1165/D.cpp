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
#define taskname "D"
int n;
ll d[300];
ll divisors_count(ll n){
    ll ans=1;
    ll i=3;
    while(n%2==0){
        ans++;
        n/=2;
    }
    while(i*i<=n){
        if(n%i==0){
            ll cnt=1;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            ans*=cnt;
        }
        i+=2;
    }
    if(n>1) ans*=2;
    return ans;
}
void solve(){
    read(n);
    FFOR(i, 0, n) read(d[i]);
    ll x=(*min_element(d, d+n))*(*max_element(d, d+n));
    FFOR(i, 0, n) if(x%d[i]){
        puts("-1");
        return;
    }
    if(divisors_count(x)!=(n+2)){
        puts("-1");
        return;
    }
    writeln(x);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int t;
    read(t);
    while(t--) solve();
}