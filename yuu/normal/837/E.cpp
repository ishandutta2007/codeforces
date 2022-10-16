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
ll x, y;
vector <ll> v;
bool npri[1000001];
int fprime(ll x){
    FFOR(j, 1, v.size()){
        if(v[j]*v[j]>x) break;
        if(x%v[j]==0) return j;
    }
    return 0;
}
ll F(ll a, ll b){
    ll d=__gcd(a, b);
    if(d>1) return F(a/d, b/d);
    if(a==1) return b;
    if(b<=1) return b;
    int res=fprime(a);
    ll best=(b/a)*a;
    if(res) FFOR(j, res, v.size()){
        if(v[j]>b) break;
        if(a%v[j]) continue;
        if(v[j]*v[j]>a) break;
        d=a/v[j];
        best=max(best, (b/v[j])*v[j]);
        best=max(best, (b/d)*d);
    }
    if(best==0) return b;
    return b-best+F(a, best);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    v.pb(0);
    FFOR(i, 2, 1000000) if(!npri[i]){
        v.pb(i);
        for(int j=i+i; j<=1000000; j+=i) npri[j]=1;
    }
    read(x);
    read(y);
    writeln(F(x, y));
}