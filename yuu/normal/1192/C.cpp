#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "C"
set <string> w[11];
const string alphabet="0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
//const string alphabet="qwertyuiopasdfghjklzxcvbnm";
const int sz=alphabet.size();
int val[256];
ll ans=0;
int cnt[64][64];
ll f[64][64][64];
const int base=998244353;
ll get(int x, int y, int z){
    if(x>y) swap(x, y);
    if(y>z) swap(y, z);
    if(x>y) swap(x, y);
    return f[x][y][z];
}
void solve(set <string> &w){
    if(w.empty()) return;
    FOR(i, 0, sz) FOR(j, 0, sz) cnt[i][j]=0;
    for(auto &s: w) cnt[val[s[0]]][val[s.back()]]++;
//    FFOR(i, 0, sz) FFOR(j, 0, sz) cerr<<cnt[i][j]<<" \n"[j+1==sz];
    FFOR(i, 0, sz) FFOR(j, i, sz) FFOR(k, j, sz){
        f[i][j][k]=0;
        FFOR(l, 0, sz) f[i][j][k]=(f[i][j][k]+1LL*cnt[i][l]*cnt[j][l]*cnt[k][l])%base;
    }
//    bug(f[3][3][3]);
    FFOR(i, 0, sz) FFOR(j, i, sz) FFOR(k, i, sz) FFOR(l, k, sz){
        ans=(ans+((get(i, j, k)*get(i, j, l))%base)*((get(j, k, l)*get(i, k, l))%base)*(1+(j>i))*(1+(l>k))*(1+(k>i)))%base;
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    FFOR(i, 0, sz) val[alphabet[i]]=i;
//    bug(sz);
    {
        int n;
        cin>>n;
        string s;
        FOR(i, 1, n){
            cin>>s;
            w[s.size()].insert(s);
            reverse(s.begin(), s.end());
            w[s.size()].insert(s);
        }
    }
    FOR(i, 3, 10) solve(w[i]);
    writeln(ans);
}