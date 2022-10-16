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
string a, b;
vector <pair <char, int>> pa, pb;
void make(string &s, vector <pair <char, int>> &t){
    t.clear();
    for(char c: s) if((t.empty())||(t.back().first!=c)) t.pb(mp(c, 1));
    else t.back().second++;
}
void solve(){
    cin>>a>>b;
    make(a, pa);
    make(b, pb);
    if(pa.size()!=pb.size()){
        puts("NO");
        return;
    }
    FFOR(i, 0, pa.size()){
        if(pa[i].first!=pb[i].first){
            puts("NO");
            return;
        }
        if(pb[i].second<pa[i].second){
            puts("NO");
            return;
        }
    }
    puts("YES");
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int n;
    cin>>n;
    while(n--) solve();
}