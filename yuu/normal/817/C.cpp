#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
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
#define taskname "C"
ll n, s;
vector <int> m;
bool done[20][171];
ll g[20][171];
ll a[171];
ll G(int i, int s){
    if(s<0) return 0;
    if(done[i][s]) return g[i][s];
    done[i][s]=1;
    if(i==0) return g[i][s]=(s==0);
    DFOR(j, min(9, s), 0) g[i][s]+=G(i-1, s-j);
    return g[i][s];
}
ll F(int i, int s){
    if(s<0) return 0;
    if(i>=m.size()) return (s==0);
    ll res=0;
    DFOR(j, m[i]-1, 0) res+=G(m.size()-i-1, s-j);
    return res+F(i+1, s-m[i]);
}
void make(ll n){
    m.clear();
    while(n>0){
        m.pb(n%10);
        n/=10;
    }
    reverse(m.begin(), m.end());
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(s);
    make(n);
    FOR(i, 1, 170) a[i]=F(0, i);
    ll ans=0;
    FOR(i, 1, 170){
        if(s+i-1>=n) break;
        make(s+i-1);
        ans+=a[i]-F(0, i);
    }
    writeln(ans);
}