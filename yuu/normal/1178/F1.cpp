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
#define taskname "F"
#define next Kafuu_Chino
int n, m;
int c[1000001];
vector <int> a;
int first[501];
int last[501];
int next[2001];
int mi[2001][2001];
bool done[2001][2001];
ll f[2001][2001];
const ll base=998244353;
ll F(int u, int v){
    if(u>v) return 1;
    if(done[u][v]) return f[u][v];
    done[u][v]=1;
    if(u==v) return f[u][v]=1;
    int val=mi[u][v];
    ll left=0, right=0, mid=1;
    {
        int x=first[val];
        while(x!=last[val]){
            mid=(mid*F(x+1, next[x]-1))%base;
            x=next[x];
        }
    }
    {
        int near=0;
        FOR(i, last[val], v){
            near=max(near, last[a[i]]);
            if(i==near) right=(right+(F(last[val]+1, i)*F(i+1, v))%base)%base;
        }
    }
    {
        int near=n+1;
        DFOR(i, first[val], u){
            near=min(near, first[a[i]]);
            if(i==near) left=(left+(F(i, first[val]-1)*F(u, i-1))%base)%base;
        }
    }
//    bug(u);
//    bug(v);
//    bug(left);
//    bug(right);
//    bug(mid);
    return f[u][v]=(mid*((left*right)%base))%base;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FOR(i, 1, m) read(c[i]);
    a.pb(0);
    FOR(i, 1, m) if(c[i]!=a.back()) a.pb(c[i]);
    m=a.size()-1;
    FOR(i, 1, m) if(first[a[i]]==0) first[a[i]]=i;
    DFOR(i, m, 1) if(last[a[i]]==0) last[a[i]]=i;
//    bug(a.size());
//    bug(first[1]);
//    bug(first[2]);
//    bug(first[3]);
//    bug(last[1]);
//    bug(last[2]);
//    bug(last[3]);
    FOR(i, 1, n) FOR(j, i+1, n){
        if(first[i]>last[j]||first[j]>last[i]) continue;
        if(first[i]<=first[j]&&last[i]>=last[j]) continue;
        writeln(0);
        return 0;
    }
    FOR(i, 1, m) mi[i][i]=a[i];
    FOR(len, 2, m){
        FOR(i, 1, m){
            int j=i+len-1;
            if(j>m) break;
            mi[i][j]=min(mi[i][j-1], mi[i+1][j]);
        }
    }
//    FOR(i, 1, m) FOR(j, i, m) cerr<<mi[i][j]<<" \n"[j==m];
    FOR(i, 1, m) FOR(j, i+1, m) if(a[i]==a[j]){
        next[i]=j;
        break;
    }
//    bug(F(1, 3));
//    bug(F(1, 2));
//    bug(F(1, 1));
//    bug(F(2, 2));
//    bug(F(2, 3));
//    bug(F(3, 3));
    writeln(F(1, m));
}