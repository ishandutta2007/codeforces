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
#define taskname "B"
ll k;
ll count(ll n){
    if(n==0) return 0;
    ll low=1, high=10;
    ll res=0;
    FOR(d, 1, 1000){
        if(n<high){
            res+=(n-low+1)*d;
            break;
        }
        else{
            res+=(high-low)*d;
            low=high;
            high*=10;
        }
    }
    return res;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(k);
    ll low=1, high=k, res;
    while(low<=high){
        ll mid=(low+high)/2;
        if(count(mid)>=k){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    k-=count(res-1);
    stringstream ss;
    ss<<res;
    string s;
    ss>>s;
    putchar(s[k-1]);
}