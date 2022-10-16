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
#define taskname "C1"
int n, m;
int a[51];
int w[51];
ll f[51][51][51];
const ll base=998244353;
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
bool done[100001];
ll iv[100001];
ll inverse(ll x){
    if(x<=100000){
        if(done[x]) return iv[x];
        done[x]=1;
        return iv[x]=power(x, base-2);
    }
    else return power(x, base-2);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) read(w[i]);
    FOR(i, 1, n){
        ll we[2];
        ll sum=0;
        we[0]=we[1]=0;
        FOR(j, 1, n){
            if(j!=i) we[a[j]]+=w[j];
            sum+=w[j];
        }
        FOR(x, 0, m) FOR(y, 0, m) FOR(z, 0, m) f[x][y][z]=0;
        f[0][0][0]=1;
        FFOR(x, 0, m) FOR(y, 0, m) FOR(z, 0, m) if(f[x][y][z]){///y: 1 chosen, z: 0 chosen, t: i chosen
            int t=x-y-z;
            if(t<0) break;
            ll sa=sum+y-z;
            if(a[i]) sa+=t;
            else sa-=t;
            ll s0=we[0]-z;
            ll s1=we[1]+y;
            ll p=f[x][y][z];
            p*=inverse(sa);
            p%=base;
            sa-=s0+s1;
            f[x+1][y+1][z]=(s1*p+f[x+1][y+1][z])%base;
            f[x+1][y][z+1]=(s0*p+f[x+1][y][z+1])%base;
            f[x+1][y][z]=(sa*p+f[x+1][y][z])%base;
        }
        ll ept=0;
        FOR(y, 0, m) FOR(z, 0, m) if(f[m][y][z]){
            int t=m-y-z;
            if(t<0) break;
            ll real=w[i]+(a[i]?t:-t);
            ept=(ept+1LL*f[m][y][z]*real)%base;
        }
        writeln(ept);
    }
}