#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "E"
ll f[1000101];
ll r[1000101];
int p[1000101];
const ll base=1000000007;
ll power(ll a, ll x){
    if(x==0) return 1;
    ll t=power(a, x/2);
    t=(t*t)%base;
    if(x%2) t=(t*a)%base;
    return t;
}
inline ll C(int n, int k){
    return ((f[n]*r[n-k])%base*r[k])%base;
}
ll Candy(int n, int k){
    return C(n+k-1, k-1);
}
vector <int> v;
void solve(){
    ll x, y;
    read(x);
    read(y);
    v.clear();
    while(x>1){
        int i=p[x];
        v.pb(0);
        while(x%i==0){
            x/=i;
            v.back()++;
        }
    }
    ll ans=1;
    for(int x: v) ans=(ans*Candy(x, y))%base;
    ans=(ans*power(2, y-1))%base;
    if(ans<0) ans+=base;
    writeln(ans);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    f[0]=1;
    FOR(i, 1, 1000100) f[i]=(f[i-1]*i)%base;
    FOR(i, 0, 1000100) r[i]=power(f[i], base-2);
    FOR(i, 2, 1000100) if(p[i]==0) for(int j=i; j<=1000100; j+=i) if(p[j]==0) p[j]=i;
    int q;
    read(q);
    while(q--) solve();
}