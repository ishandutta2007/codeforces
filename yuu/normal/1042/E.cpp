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
#define taskname "E"
#define up Mahou
#define down Shoujo
#define left Kafuu
#define right Chino
int n, m;
ll a[1001][1001];
const ll base=998244353;
ll f[1001][1001];
vector <pair <int, int> > v;
int r, c;
ll power(ll x, ll y){
    if(y==0) return 1;
    ll t=power(x, y/2);
    t=(t*t)%base;
    if(y%2) t=(t*x)%base;
    return t;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, n) FOR(j, 1, m){
        read(a[i][j]);
        v.pb(mp(i, j));
    }
    sort(v.begin(), v.end(), [](pair <int, int> A, pair <int, int> B){
        return a[A.first][A.second]<a[B.first][B.second];
    });
    read(r);
    read(c);
    int i=0;
    ll sum_0=0;
    ll sum_1_ud=0;
    ll sum_1_lr=0;
    for(auto p: v){
        while((i<v.size())&&(a[v[i].first][v[i].second]<a[p.first][p.second])){
            sum_0=(sum_0+f[v[i].first][v[i].second]+((ll)v[i].first)*v[i].first+((ll)v[i].second)*v[i].second)%base;
            sum_1_ud=(sum_1_ud-v[i].first*2)%base;
            sum_1_lr=(sum_1_lr-v[i].second*2)%base;
            i++;
        }
        f[p.first][p.second]=sum_0+sum_1_ud*p.first+sum_1_lr*p.second+(ll(i))*(p.first*p.first+p.second*p.second);
        f[p.first][p.second]%=base;
        f[p.first][p.second]=(f[p.first][p.second]*power(i, base-2))%base;
        if(p.first==r&&p.second==c) break;
    }
//    FOR(i, 1, n) FOR(j, 1, m){
//        write(f[i][j]);
//        putchar(" \n"[j==m]);
//    }
    f[r][c]=(f[r][c]+base)%base;
    writeln(f[r][c]);
}