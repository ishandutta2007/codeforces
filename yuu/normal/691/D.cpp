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
using ll=long long;
using ld=long double;
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
int n, m;
int p[1000001];
int r[1000001];
vector <int> pos[1000001];
vector <int> value[1000001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void uni(int u, int v){
    u=root(u); v=root(v);
    if(u!=v){
        if(r[u]>r[v]) swap(u, v);
        r[u]+=r[v];
        r[v]=u;
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, n) read(p[i]);
    FOR(i, 1, n) r[i]=-1;
    {
        int a, b;
        FOR(i, 1, m){
            read(a);
            read(b);
            uni(a, b);
        }
    }
    FOR(i, 1, n) pos[root(i)].pb(i), value[root(i)].pb(p[i]);
    FOR(i, 1, n) if(i==root(i)){
        sort(value[i].begin(), value[i].end());
        reverse(value[i].begin(), value[i].end());
        FFOR(j, 0, pos[i].size()) p[pos[i][j]]=value[i][j];
    }
    FOR(i, 1, n){
        write(p[i]);
        putchar(" \n"[i==n]);
    }
}