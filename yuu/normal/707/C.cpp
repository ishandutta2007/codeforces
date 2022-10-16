#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
ll n;
pair <ll, ll> check_c(){
    ll a=2, b, t;
    while(a*a<=n){
        b=n-a*a;
        t=round(sqrt(b));
        if(t*t==b&&b!=a){
            b=t;
            return mp(b*a*2, abs(a*a-b*b));
        }
        a++;
    }
    return mp(0, 0);
}
pair <ll, ll> check_b(){
    ll m=n/2;
    if(m==1) return mp(0, 0);
    return mp(m*m-1, m*m+1);
}
pair <ll, ll> check_a(){
    ll z=1;
    while(z*z<n){
        if(n%z==0){
            ll t=n/z;
            if(t%2==z%2){
                ll a=(t+z)/2;
                ll b=(t-z)/2;
                return mp(a*b*2, a*a+b*b);
            }
        }
        z++;
    }
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    pair <ll, ll> res;
    if(n%2==0){
        res=check_b();
        if(res.first){
            write(res.first);
            putchar(' ');
            write(res.second);
            return 0;
        }
    }
    res=check_c();
    if(res.first){
        write(res.first);
        putchar(' ');
        write(res.second);
        return 0;
    }
    res=check_a();
    if(res.first){
        write(res.first);
        putchar(' ');
        write(res.second);
        return 0;
    }
    write(-1);
}