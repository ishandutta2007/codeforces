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
#define taskname "B"
int n;
int a[100001];
bool solve(){
    ///all number are pair wise different
    a[0]=-1;
    DFOR(i, n, 2) a[i]-=a[i-1]+1;
    int ans=0;
    for(int i=n; i>0; i-=2) ans=(ans+a[i])%2;
    return ans;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n) read(a[i]);
    if(n==1){
        if(a[1]%2==0) puts("cslnb");
        else puts("sjfnb");
        return 0;
    }
    a[0]=-1e9;
    sort(a+1, a+n+1);
    FOR(i, 1, n){
        int j=i;
        while((j<n)&&(a[j+1]==a[j])) j++;
        if(i==j) continue;
        if(j-i+1>2){
            puts("cslnb");
            return 0;
        }
        if(a[i]==0){///2 0s
            puts("cslnb");
            return 0;
        }
        a[i]--;
        FOR(j, 2, n) if(a[j]==a[j-1]){
            puts("cslnb");
            return 0;
        }
        if(solve()){///first person win
            puts("cslnb");
        }
        else puts("sjfnb");
        return 0;
    }
    if(solve()){///first person win
        puts("sjfnb");
    }
    else puts("cslnb");
}