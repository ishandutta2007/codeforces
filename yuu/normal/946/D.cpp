#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "D"
int n, m, k;
string s;
vector <int> pos;
int g[501];
int e[501];
int f[501];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(k);
    FOR(i, 1, n){
        cin>>s;
        pos.clear();
        FFOR(j, 0, s.size()) if(s[j]=='1') pos.pb(j);
        FOR(x, pos.size(), k) g[x]=0;
        FOR(x, 1, pos.size()){
            g[pos.size()-x]=pos[x-1]-pos[0]+1;
            FFOR(a, 1, pos.size()){
                if(a+x-1>=pos.size()) break;
                g[pos.size()-x]=min(g[pos.size()-x], pos[a+x-1]-pos[a]+1);
            }
        }
        FOR(j, 0, k) e[j]=1e9;
        FOR(j, 0, k){
            FOR(l, 0, k){
                if(j+l>k) break;
                e[j+l]=min(e[j+l], f[j]+g[l]);
            }
        }
        FOR(j, 0, k) f[j]=e[j];
    }
    writeln(f[k]);
}