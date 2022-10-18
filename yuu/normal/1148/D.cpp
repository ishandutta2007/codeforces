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
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "D"
int n;
int a[300001];
int b[300001];
vector <int> ab, ba;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n){
        read(a[i]);
        read(b[i]);
    }
    int cnt=0;
    FOR(i, 1, n) if(a[i]<b[i]) ab.pb(i); else ba.pb(i);
    writeln(max(ab.size(), ba.size()));
    if(ab.size()>ba.size()){
        sort(ab.begin(), ab.end(), [](int x, int y){
            return a[x]>a[y];
        });
        for(int x: ab){
            write(x);
            putchar(' ');
        }
    }
    else{
        sort(ba.begin(), ba.end(), [](int x, int y){
            return a[x]<a[y];
        });
        for(int x: ba){
            write(x);
            putchar(' ');
        }
    }
}