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
#define taskname "F"
int n, m;
int k[200001];
int r[200001];
vector <int> off[400001];
vector <int> best[200001];
bool check(int last){
    FOR(i, 1, last) off[i].clear();
    FOR(i, 1, n) for(int p: best[i]) if(p<=last){
        off[p].pb(i);
        break;
    }
    FOR(i, 1, n) r[i]=k[i];
    int coin=0;
    FOR(i, 1, last){
        coin++;
        for(int p: off[i]) while(coin&&r[p]){
            coin--;
            r[p]--;
        }
    }
    FOR(i, 1, n) coin-=r[i]*2;
    return (coin>=0);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FOR(i, 1, n) read(k[i]);
    FOR(i, 1, m){
        int d, t;
        read(d);
        read(t);
        best[t].pb(d);
    }
    FOR(i, 1, n) sort(best[i].begin(), best[i].end());
    FOR(i, 1, n) reverse(best[i].begin(), best[i].end());
    int low=1, high=400000, mid, ans=0;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
//    bug(check(1));
    writeln(ans);
}