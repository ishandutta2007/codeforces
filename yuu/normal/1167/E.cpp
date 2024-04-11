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
int n, x;
int a[1000001];
int minpos[1000002];
int maxpos[1000001];
bool check(int l, int r){
    int old=0;
    FOR(i, 1, n){
        if(a[i]<=r&&a[i]>=l) continue;
        if(a[i]<old) return 0;
        old=a[i];
    }
    return 1;
}
int find_first(){
    int low=1, high=x, res, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(check(1, mid)){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}
int find_last(){
    int low=1, high=x, res, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid, x)){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(x);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) maxpos[a[i]]=i;
    FOR(i, 1, x+1) minpos[i]=n+1;
    DFOR(i, n, 1) minpos[a[i]]=i;
    FOR(i, 1, x) maxpos[i]=max(maxpos[i], maxpos[i-1]);
    DFOR(i, x, 1) minpos[i]=min(minpos[i], minpos[i+1]);
    ll ans=0;
    int r=find_first();
    int maxl=find_last();
//    bug(maxl);
//    bug(check(3, 3));
    FOR(l, 1, maxl){
        r=max(r, l);
        while((r<x)&&(minpos[r+1]<maxpos[l-1])) r++;
//        cerr<<l<<' '<<r<<'\n';
        ans+=x-r+1;
    }
    writeln(ans);
}