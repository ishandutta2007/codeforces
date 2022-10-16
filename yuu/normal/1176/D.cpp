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
int n, b;
int p[2750132];
vector <int> primes;
int c[2750132];
vector <int> a;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    primes.pb(0);
    FOR(i, 2, 2750131) if(p[i]==0){
        primes.pb(i);
        for(int j=i; j<=2750131; j+=i) if(!p[j]) p[j]=i;
    }
    read(n);
    FOR(i, 1, n*2){
        read(b);
        c[b]++;
    }
    DFOR(i, 2750131, 2) if(p[i]!=i) if(c[i]){
        FOR(x, 1, c[i]) a.pb(i);
        c[i/p[i]]-=c[i];
    }
    FOR(i, 2, 2750131) if(p[i]==i) if(c[i]){
        FOR(x, 1, c[i]) a.pb(i);
        c[primes[i]]-=c[i];
    }
    for(int x: a){
        write(x);
        putchar(' ');
    }
}