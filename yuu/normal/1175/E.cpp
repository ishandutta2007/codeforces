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
#define taskname "E"
int n, m;
int f[500001][20];
void query(){
    int x, y;
    read(x);
    read(y);
    if(f[x][19]<y){
        puts("-1");
        return;
    }
    int ans=0;
    DFOR(i, 18, 0){
        if(f[x][i]<y){
            x=f[x][i];
            ans=ans*2+1;
        }
        else ans=ans*2;
    }
    ans++;
    writeln(ans);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    {
        int l, r;
        FOR(i, 1, n){
            read(l);
            read(r);
            f[l][0]=max(f[l][0], r);
        }
    }
    FFOR(i, 0, 20){
        FOR(j, 1, 500000) f[j][i]=max(f[j][i], f[j-1][i]);
        if(i<19) FOR(j, 0, 500000) f[j][i+1]=f[f[j][i]][i];
    }
    FOR(i, 1, m) query();
}