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
#define taskname "D"
int n;
string s;
string ch="RGB";
int f[200001][3];
int t[200001][3];
void track(int i, int j){
    if(i) track(i-1, t[i][j]);
    putchar(ch[j]);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n>>s;
    FFOR(i, 0, n) s[i]=ch.find(s[i]);
    FFOR(i, 0, 3) f[0][i]=1;
    f[0][s[0]]=0;
    FFOR(i, 1, n){
        FOR(j, 0, 3) f[i][j]=1e9;
        FFOR(j, 0, 3) FFOR(k, 0, 3) if(j!=k){
            if(f[i][j]>f[i-1][k]+(j!=s[i])){
                f[i][j]=f[i-1][k]+(j!=s[i]);
                t[i][j]=k;
            }
        }
    }
    int best=0;
    FFOR(j, 1, 3) if(f[n-1][j]<f[n-1][best]) best=j;
    writeln(f[n-1][best]);
    track(n-1, best);
}