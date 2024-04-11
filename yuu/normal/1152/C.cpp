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
#define taskname "C"
///lcm (a+k, b+k)
///d|(a+k)&&d|(b+k) <=> a%d==b%d -> (a-b)%d==0
///gcd(a+k, b+k)=gcd(a-b, b+k)?
ll a, b, n;
ll ans;
ll best_k=0;
void check(ll x){
    ///(a+k)
    ll k=x-a%x;
    if(k==x) k=0;
    ll now=(a+k)/__gcd((a+k), (b+k))*(b+k);
    if(now<ans){
        ans=now;
        best_k=k;
    }
    else if(now==ans) best_k=min(best_k, k);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(a);
    read(b);
    if(a>b) swap(a, b);
    if((b-a)<=1){
        writeln(0);
        return 0;
    }
    n=b-a;
    ans=(a/__gcd(a, b))*b;
    for(ll x=1; x*x<=n; x++){
        if(n%x==0){
            check(x);
            check(n/x);
        }
    }
//    bug(ans);
    writeln(best_k);
}