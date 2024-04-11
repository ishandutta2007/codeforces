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
#define taskname "C"
vector <int> lim;
ll f[21][2][4];
ll count(ll x){
    lim.clear();
    FOR(i, 0, 19){
        lim.pb(x%10);
        x/=10;
    }
    reverse(lim.begin(), lim.end());
    FOR(i, 0, 20) FOR(b, 0, 1) FOR(z, 0, 3) f[i][b][z]=0;
    f[0][0][0]=1;
    FFOR(i, 0, 20) FOR(b, 0, 1) FOR(z, 0, 3) if(f[i][b][z]){
        f[i+1][(b)||lim[i]][z]+=f[i][b][z];
        if(z!=3){
            if(b) f[i+1][b][z+1]+=f[i][b][z]*9;
            else if(lim[i]){
                f[i+1][1][z+1]+=f[i][b][z]*(lim[i]-1);
                f[i+1][b][z+1]+=f[i][b][z];
            }
        }
    }
    ll res=0;
    FOR(b, 0, 1) FOR(z, 0, 3) res+=f[20][b][z];
    return res;
}
void solve(){
    ll l, r;
    read(l);
    read(r);
    writeln(count(r)-count(l-1));
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    int t;
    read(t);
    while(t--) solve();
}