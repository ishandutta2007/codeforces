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
pair <int, int> b[200001];
bool goodl[200001];
bool goodr[200001];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n){
        read(b[i].first);
        b[i].second=i;
    }
    sort(b+1, b+n+1);
    if(n<=3){
        puts("1");
        return 0;
    }
    goodl[1]=goodl[2]=goodr[n-1]=goodr[n]=1;
    FOR(i, 3, n) if(b[i].first-b[i-1].first==b[i-1].first-b[i-2].first) goodl[i]=goodl[i-1];
    else goodl[i]=0;
    DFOR(i, n-2, 1) if(b[i+2].first-b[i+1].first==b[i+1].first-b[i].first) goodr[i]=goodr[i+1];
    else goodr[i]=0;
//    FOR(i, 1, n) cerr<<b[i].first<<" \n"[i==n];
//    FOR(i, 1, n) cerr<<goodl[i]<<" \n"[i==n];
//    FOR(i, 1, n) cerr<<goodr[i]<<" \n"[i==n];
    if(goodr[2]){
        writeln(b[1].second);
        return 0;
    }
    if(goodl[n-1]){
        writeln(b[n].second);
        return 0;
    }
    FFOR(i, 2, n) if(goodl[i-1]&&goodr[i+1]){
        if((i>2)&&(b[i+1].first-b[i-1].first!=b[i-1].first-b[i-2].first)) continue;
        if((i<n-1)&&(b[i+2].first-b[i+1].first!=b[i+1].first-b[i-1].first)) continue;
        writeln(b[i].second);
        return 0;
    }
    puts("-1");
}