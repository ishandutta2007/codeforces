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
ll n, k;
ll v, a[5001];
ll trace[5001];
bool done[5001];
inline void output(ll c, ll x, ll y){
    write(c);
    putchar(' ');
    write(x);
    putchar(' ');
    writeln(y);
}
vector <ll> temp;
vector <ll> sp;
bool bad[5001];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(k);
    read(v);
    ll s=0;
    FOR(i, 1, n){
        read(a[i]);
        s+=a[i];
    }
    if(s<v){
        puts("NO");
        return 0;
    }
    if(v%k==0){
        puts("YES");
        FFOR(i, 1, n) if(a[i])  output((a[i]-1)/k+1, i, n);
        if(v>0) output(v/k, n, 1);
        return 0;
    }
    done[0]=1;
    FOR(i, 1, n){
        temp.clear();
        FFOR(j, 0, k) if(done[j]) temp.pb(j);
        for(ll x: temp) if(!done[(x+a[i])%k]){
            done[(x+a[i])%k]=1;
            trace[(x+a[i])%k]=i;
        }
    }
    if(!done[v%k]){
        puts("NO");
        return 0;
    }
    puts("YES");
    ll x=v%k;
    while(x){
        sp.pb(trace[x]);
        x=(x-a[trace[x]])%k;
        x=(x+k)%k;
    }
    for(ll x: sp) bad[x]=1;
    ll sink;
    if(sp.size()>1) sink=sp.back();
    else if(sp[0]==1) sink=n;
    else sink=1;
    FFOR(i, 1, sp.size()) if(a[sp[i]]) output((a[sp[i]]-1)/k+1, sp[i], sp[0]);
    FOR(i, 1, n)if(a[i]){
        if((!bad[i])&&(i!=sink)) output((a[i]-1)/k+1, i, sink); else if(bad[i]) v-=a[i];
    }
    if(v>0) output(v/k, sink, sp[0]);
    else if(v<0) output(-v/k, sp[0], sink);
}