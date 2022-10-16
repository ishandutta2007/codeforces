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
#define taskname "D"
struct st{
    ll k, b;
    pair <ll, ll> x;
    bool operator <(st a){
        return x.first*a.x.second<a.x.first*x.second;
    }
} d;
vector <st> y;
inline void unify(pair <ll, ll> &x){
    ll d=__gcd(abs(x.first), abs(x.second));
    x.first/=d;
    x.second/=d;
    if(x.second<0){
        x.second=-x.second;
        x.first=-x.first;
    }
}
pair <ll, ll> now;
inline pair <ll, ll> operator +(pair <ll, ll> a, pair <ll, ll> b){
    a.first+=b.first;
    a.second+=b.second;
    return a;
}
inline pair <ll, ll> operator -(pair <ll, ll> a, pair <ll, ll> b){
    a.first-=b.first;
    a.second-=b.second;
    return a;
}
inline void operator +=(pair <ll, ll> &a, pair <ll, ll> b){
    a=a+b;
}
inline void operator -=(pair <ll, ll> &a, pair <ll, ll> b){
    a=a-b;
}
int n;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n){
        read(d.k);
        read(d.b);
        if(d.k==0) continue;
        d.x=mp(-d.b, d.k);
        unify(d.x);
        y.pb(d);
        if(d.k<0) now+=mp(d.k, d.b);
    }
    sort(y.begin(), y.end());
    int ans=0;
    pair <ll, ll> last=mp(0, 0);
    pair <ll, ll> New=now;
    for(auto a: y){
        if(a.x==last){
            if(a.k<0) New-=mp(a.k, a.b);
            else New+=mp(a.k, a.b);
        }
        else{
            if(New!=now){
                ans++;
                now=New;
            }
            last=a.x;
            if(a.k<0) New-=mp(a.k, a.b);
            else New+=mp(a.k, a.b);
        }
    }
    if(New!=now){
        ans++;
        now=New;
    }
    writeln(ans);
}