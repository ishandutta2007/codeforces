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
#define taskname "E"
int n;
class my_vector{
public:
    int a[7];
    int sz;
    my_vector(){
        sz=0;
    }
    bool empty(){
        return sz==0;
    }
    void push_back(int x){
        a[sz]=x;
        sz++;
    }
    int size(){
        return sz;
    }
};
#define up KafuuChino
const ll base=1000000007;
int most=0;
ll ans=0;
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
int p[1000001];
vector <int> primes;
ll fact[1000001];
ll rev[1000001];
ll f[1000001];
int dist[1000001];
ll P(int n, int k){
    return (fact[n]*rev[n-k])%base;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    fact[0]=1;
    FOR(i, 2, n) if(p[i]==0){
        primes.pb(i);
        for(int j=i; j<=n; j+=i) if(p[j]==0) p[j]=i;
    }
    FOR(i, 2, n) dist[i]=dist[i/p[i]]+1;
    FOR(i, 1, n) fact[i]=(fact[i-1]*i)%base;
    rev[n]=power(fact[n], base-2);
    DFOR(i, n, 1) rev[i-1]=(rev[i]*i)%base;
    f[1]=1;
    FOR(i, 1, n){
        for(int j: primes){
            int p=i*j;
            if(p>n) break;
            f[p]=(f[p]+(f[i]*P(n-n/p-1, n/i-n/p-1))%base*(n/i-n/p))%base;
        }
    }
    ll ans=0;
    int mx=*max_element(dist+1, dist+n+1);
    FOR(i, 1, n) if(dist[i]==mx) ans=(ans+f[i]*fact[n/i])%base;
    writeln(ans);
}