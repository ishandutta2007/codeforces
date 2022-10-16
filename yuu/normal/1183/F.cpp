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
int n;
int a[200001];
void solve(){
    read(n);
    FOR(i, 1, n) read(a[i]);
    sort(a+1, a+n+1);
    n=unique(a+1, a+n+1)-a-1;
    int ans=a[n];
    DFOR(i, n, 2){
        int first=0;
        if(a[i]+a[i-1]+a[i-2]<ans) break;
        DFOR(j, i-1, 1) if(a[i]%a[j]){
            if(first==0){
                first=a[j];
                ans=max(ans, a[i]+a[j]);
            }
            if(first%a[j]) break;
            DFOR(k, j-1, 1){
                if(a[i]%a[k]&&a[j]%a[k]){
                    ans=max(ans, a[i]+a[j]+a[k]);
                    break;
                }
            }
        }
    }
    writeln(ans);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int q;
    read(q);
    while(q--) solve();
}