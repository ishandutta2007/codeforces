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
ll n;
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t*=t;
    if(b%2) t*=a;
    return t;
}
int mobius[101];
bool good[101];
int f[101];
void solve(){
    read(n);
    ll ans=0;
    FOR(i, 1, 100) if(good[i]){
        ll x=pow((ld)n, (ld(1))/i)-1;
        x=max(x, 0LL);
        while(true){
            if(pow(x+1, i)<5e18){
                if(power(x+1, i)<=n) x++;
                else break;
            }
            else break;
        }
//        bug(i);
//        bug(x);
        if(x<2) break;
        ans+=(x-1)*mobius[i];
//        bug(ans);
    }
    writeln(ans);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    FOR(i, 2, 100) if(f[i]==0) for(int j=i; j<=100; j+=i) if(!f[j]) f[j]=i;
    mobius[1]=1;
    good[1]=1;
    FOR(i, 2, 100){
        int u=i;
        int old=f[u]+1;
        good[i]=1;
        while(u>1){
            if(f[u]==old) good[i]=0;
            old=f[u];
            u/=f[u];
        }
        mobius[i]=-mobius[i/f[i]];
    }
    int t;
    read(t);
    while(t--) solve();
}