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
#define taskname "A"
int n, k;
ll m;
int a, b;
ll ansmax=0;
ll ansmin=1e18;
void test(ll a, ll b){
    ll l=b-a;
    if(l<0) l+=m;
    ansmax=max(ansmax, m/__gcd(l, m));
    ansmin=min(ansmin, m/__gcd(l, m));
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(k);
    m=(ll(n))*k;
    read(a);
    read(b);
    ///s=a+1
    FFOR(i, 0, n) test(a, ((ll)k)*i+b);
    FOR(i, 1, n) test(a, ((ll)k)*i-b);
    FFOR(i, 0, n) test(k-a, ((ll)k)*i+b);
    FOR(i, 1, n) test(k-a, ((ll)k)*i-b);
    write(ansmin);
    putchar(' ');
    writeln(ansmax);
}