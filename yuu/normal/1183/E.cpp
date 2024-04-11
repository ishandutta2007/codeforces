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
#define taskname "H"
#define next SGDQ2019
int n;
ll k;
string s;
int next[101][26];
ll f[101][101];
bool done[101][101];
ll F(int u, int l){
    if(done[u][l]) return f[u][l];
    done[u][l]=1;
    if(l==0) return f[u][l]=1;
    FFOR(i, 0, 26) if(next[u][i]){
//        cerr<<u<<' '<<l<<' '<<next[u][i]<<'\n';
        f[u][l]+=F(next[u][i], l-1);
    }
    if(f[u][l]>k) f[u][l]=k+1;
    return f[u][l];
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n>>k>>s;
    s='0'+s;
    for(char &c: s) c-='a';
    DFOR(i, n-1, 0){
        FFOR(j, 0, 26) next[i][j]=next[i+1][j];
        next[i][s[i+1]]=i+1;
    }
    ll ans=0;
    DFOR(i, n, 1){
        if(F(0, i)>=k){
            ans+=k*(n-i);
            k=0;
            break;
        }
        else{
            ans+=F(0, i)*(n-i);
            k-=F(0, i);
        }
    }
    if(k){
        ans+=n;
        k--;
    }
    if(k) ans=-1;
    writeln(ans);
}