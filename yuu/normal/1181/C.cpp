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
#define taskname "C"
int n, m;
string c[1000];
string a[1000];
int h[1000];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n>>m;
    FFOR(i, 0, n) cin>>c[i];
    FFOR(j, 0, m) FFOR(i, 0, n) a[j]+=c[i][j];
    ll ans=0;
    FFOR(i, 0, m){
        FFOR(j, 0, n) if(i&&(a[i][j]==a[i-1][j])) h[j]++; else h[j]=1;
        int f=0;
        int s=0;
        int t=0;
        int e=0;
        while((s+1<n)&&(a[i][s+1]==a[i][s])) s++;
        s++;
        t=s;
        while((t+1<n)&&(a[i][t+1]==a[i][t])) t++;
        t++;
        while(t<n){
            e=t;
            while((e+1<n)&&(a[i][e+1]==a[i][e])) e++;
            e++;
            if((e-t>=t-s)&&(s-f>=t-s)){
                int mi=1e9;
                FFOR(x, s-(t-s), t+(t-s)) mi=min(mi, h[x]);
                ans+=mi;
            }
            f=s;
            s=t;
            t=e;
        }
    }
    writeln(ans);
}