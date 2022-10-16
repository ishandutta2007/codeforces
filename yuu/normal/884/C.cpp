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
#define taskname "C"
int n;
int p[100001];
bool done[100001];
int cnt;
vector <ll> v;
void dfs(int u){
    done[u]=1;
    cnt++;
    if(!done[p[u]]) dfs(p[u]);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n) read(p[i]);
    FOR(i, 1, n) if(!done[i]){
        cnt=0;
        dfs(i);
        v.pb(cnt);
    }
    sort(v.begin(), v.end());
    ll ans=0;
    for(ll x: v) ans+=x*x;
    if(v.size()>=2){
        ll x=v.back();
        v.pop_back();
        ll y=v.back();
        v.pop_back();
        ans-=x*x+y*y;
        ans+=(x+y)*(x+y);
    }
    writeln(ans);
}