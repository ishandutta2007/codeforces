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
#define taskname "C"
int n;
int p[300001];
int pos[300001];
vector <pair <int, int>> ans;
void add_move(int i, int j){
    ans.pb(mp(i, j));
    swap(p[i], p[j]);
    pos[p[i]]=i;
    pos[p[j]]=j;
}
void swap_pos(int i, int j){
    if(i==j) return;
//    cerr<<"i, j="<<i<<", "<<j<<'\n';
    if(abs(i-j)>=n/2) add_move(i, j);
    else if((max(i, j)<=n/2)||(min(i, j)>n/2)){
        int k=(max(i, j)<=n/2)?n:1;
        add_move(k, i);
        add_move(k, j);
        add_move(k, i);
    }
    else{
        if(i>j) swap(i, j);
        add_move(i, n);
        add_move(1, n);
        add_move(1, j);
        add_move(1, n);
        add_move(i, n);
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n){
        read(p[i]);
        pos[p[i]]=i;
    }
    FOR(i, 1, n) swap_pos(pos[i], i);
    writeln(ans.size());
    for(auto x: ans){
        write(x.first);
        putchar(' ');
        writeln(x.second);
    }
    #ifdef Aria
        FOR(i, 1, n) cerr<<p[i]<<" \n"[i==n];
    #endif // Aria
}