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
string a, b;
int n;
int c[256];
ll f[1000001];
ll r[1000001];
const ll base=1000000007;
ll power(ll a, ll x){
    if(x==0) return 1;
    ll t=power(a, x/2);
    t=(t*t)%base;
    if(x%2) t=(t*a)%base;
    return t;
}
ll pop(ll sc, ll co, ll x){
    sc=(sc*r[co])%base;
    sc=(sc*x)%base;
    return sc;
}
ll push(ll sc, ll co, ll x){
    co++;
    sc=(sc*co)%base;
    x++;
    sc=(sc*r[x])%base;
    return sc;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    f[0]=1;
    FOR(i, 1, 1000000) f[i]=(f[i-1]*i)%base;
    FOR(i, 0, 1000000) r[i]=power(i, base-2);
    cin>>a>>b;
    n=a.size();
    ll ans=0;
    ll sc, co;
    for(char x: a) c[x]++;
    sc=f[n];
    co=n;
    FOR(i, 'a', 'z') sc=(sc*power(f[c[i]], base-2))%base;
    int eq=1;
    FFOR(i, 0, n){
        if(!eq){
            FOR(j, a[i]+1, 'z') if(c[j]) ans=(ans+pop(sc, co, c[j]))%base;
        }
        else{
            FOR(j, a[i]+1, b[i]-1) if(c[j]) ans=(ans+pop(sc, co, c[j]))%base;
        }
        sc=pop(sc, co, c[a[i]]);
        co--;
        c[a[i]]--;
        if(a[i]<b[i]) eq=0;
    }
    eq=1;
    FOR(i, 'a', 'z') c[i]=0;
    for(char x: a) c[x]++;
    sc=f[n];
    co=n;
    FOR(i, 'a', 'z') sc=(sc*power(f[c[i]], base-2))%base;
    FFOR(i, 0, n-1){
        if(c[b[i]]==0) break;
        sc=pop(sc, co, c[b[i]]);
        co--;
        c[b[i]]--;
        if(b[i]!=a[i]) eq=0;
        if(!eq){
            DFOR(j, b[i+1]-1, 'a') if(c[j]) ans=(ans+pop(sc, co, c[j]))%base;
        }
    }
    write(ans);
}