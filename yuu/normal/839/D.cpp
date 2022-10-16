#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(ll i=j; i<=k; i++)
#define FFOR(i, j, k) for(ll i=j; i<k; i++)
#define DFOR(i, j, k) for(ll i=j; i>=k; i--)
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
#define MAX 1000005
const ll base=1000000007;
ll p2[MAX];
ll pri[MAX];
ll a;
ll n;
vector <pair <ll, ll> > p;
ll d=1;
ll c[MAX];
ll f[MAX];
void backtrack(ll u, ll v){
    if(u==p.size()) c[d]++;
    else{
        backtrack(u+1, 0);
        if(v<p[u].second){
            d*=p[u].first;
            backtrack(u, v+1);
            d/=p[u].first;
        }
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    p2[0]=1;
    FFOR(i, 1, MAX) p2[i]=(p2[i-1]*2)%base;
    FOR(i, 2, 1000000) if(!pri[i]) for(ll j=i; j<=1000000; j+=i) pri[j]=i;
    read(n);
    FOR(i, 1, n){
        read(a);
        if(a==1) continue;
        p.clear();
        p.pb(mp(pri[a], 0));
        while(a>1){
            if(pri[a]!=p.back().first) p.pb(mp(pri[a], 0));
            p.back().second++;
            a/=pri[a];
        }
        backtrack(0, 0);
    }
    ll ans=0;
    DFOR(i, 1000000, 2){
        if(c[i]==0) continue;
        f[i]=((ll(c[i]))*p2[c[i]-1])%base;
        for(int j=2*i; j<=1000000; j+=i) f[i]-=f[j];
        ans=(ans+f[i]*i)%base;
    }
    writeln((ans+base)%base);
    return 0;
}