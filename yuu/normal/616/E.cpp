#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(ll i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(ll i=(j); i<(k); i++)
#define DFOR(i, j, k) for(ll i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
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
ll n, m;
const ll base=1000000007;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    ll i=1;
    ll ans=0;
    while(n/i>1000000){
        if(i>m) break;
        ans=(ans+n%i)%base;
        i++;
    }
    ans%=base;
    ///n/i<i
    if(i<=m) DFOR(a, 1000000, 1){
        ///n/i=a
        ll low=n/(a+1)-2;
        while(low*(a+1)<=n) low++;
        if(low>m) break;
        ll high=n/a+2;
        while(high*a>n) high--;
        high=min(high, m);
        if(low>high) continue;
        ans=(ans+((n%low)%base)*((high-low+1)%base))%base;
        ll temp=high-low;
        if(temp%2) temp=((temp%base)*(((temp+1)/2)%base))%base;
        else temp=(((temp/2)%base)*((temp+1)%base))%base;
        ans=(ans-a*temp)%base;
    }
    if(m>n) ans=(ans+(n%base)*((m-n)%base))%base;
    ans=(ans+base)%base;
    writeln(ans);
}