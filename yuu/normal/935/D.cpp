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
#define taskname "D"
ll n, m;
const ll base=1000000007;
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
ll s1[100001], s2[100001];
ll f[100001];
ll invm, invm2;
bool done[100001];
ll F(int u){
    if(done[u]) return f[u];
    done[u]=1;
    if(u==n){
        if(s1[u]){
            if(s2[u]) return f[u]=s1[u]>s2[u];
            else return f[u]=((s1[u]-1)*invm)%base;
        }
        else{
            if(s2[u]) return f[u]=((m-s2[u])*invm)%base;
            else return f[u]=((m*(m-1)/2)%base*invm2)%base;
        }
    }
    if(s1[u]){
        if(s2[u]){
            if(s1[u]==s2[u]) return f[u]=F(u+1);
            return f[u]=s1[u]>s2[u];
        }
        else return f[u]=((s1[u]-1+F(u+1))*invm)%base;
    }
    else{
        if(s2[u]) return f[u]=((m-s2[u]+F(u+1))*invm)%base;
        else return f[u]=((m*(m-1)/2)%base*invm2+F(u+1)*invm)%base;
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    invm=power(m, base-2);
    invm2=power((m*m)%base, base-2);
    FOR(i, 1, n) read(s1[i]);
    FOR(i, 1, n) read(s2[i]);
    write(F(1));
}