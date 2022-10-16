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
#define taskname "D"
ll a1, b1, a2, b2, l, r;
void extended_euclid(ll a, ll b, ll &x, ll &y){
    ///a*x+b*y=1
    if(b==0){
        x=1;
        y=0;
    }
    else{
        extended_euclid(b, a%b, y, x);
        y-=(a/b)*x;
    }
}
void linear_diophantine(ll a, ll b, ll c, ll &x, ll &y){
    ///ax+by=c
    ll d=__gcd(a, b);
    a/=d;
    b/=d;
    c/=d;
    extended_euclid(a, b, x, y);
    x*=c;
    y*=c;
    a*=d;
    b*=d;
    c*=d;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(a1);
    read(b1);
    read(a2);
    read(b2);
    read(l);
    read(r);
    l=max(l, b1);
    l=max(l, b2);
    ll x, y;
    if((b2-b1)%__gcd(a1, a2)){
        writeln(0);
        return 0;
    }
    linear_diophantine(a1, a2, b2-b1, x, y);
    ll lowx=(l-b1)/a1-4;
    while(lowx*a1+b1<l) lowx++;
    ll highx=(r-b1)/a1+4;
    while(highx*a1+b1>r) highx--;
    ll q=a2/__gcd(a1, a2);
    x%=q;
    ///dl>=(lowx-x)/q;
    ll dl=(lowx-x)/q-4;
    while(dl*q+x<lowx) dl++;
    ll dr=(highx-x)/q+4;
    while(dr*q+x>highx) dr--;
    writeln(max(0LL, dr-dl+1));
}