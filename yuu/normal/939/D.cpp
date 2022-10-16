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
int n;
string s, t;
int r[256];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void uni(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return;
    r[u]+=r[v];
    r[v]=u;
}
vector <int> v[256];
vector <pair <char, char> > ans;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>n>>s>>t;
    FOR(i, 'a', 'z') r[i]=-1;
    FFOR(i, 0, n) uni(s[i], t[i]);
    FOR(i, 'a', 'z') v[root(i)].pb(i);
    FOR(i, 'a', 'z') if(v[i].size()>1) FFOR(j, 1, v[i].size()) ans.pb(mp(v[i][j-1], v[i][j]));
    writeln(ans.size());
    for(pair <char, char> p: ans){
        putchar(p.first);
        putchar(' ');
        putchar(p.second);
        putchar('\n');
    }
}