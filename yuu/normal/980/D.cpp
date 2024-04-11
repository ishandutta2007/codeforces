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
ll a[5001];
int r[5001];
int root(int u){
    if(r[u]<0) return u;
    if(r[u]==0){
        bug(u);
        exit(-1);
    }
    return r[u]=root(r[u]);
}
void uni(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return;
    r[u]+=r[v];
    r[v]=u;
}
bool is_perfect_square(ll f){
    if(f<0) return 0;
    if(f<=1) return 1;
    ll a=sqrt(f);
    while(a*a<f) a++;
    return a*a==f;
}
vector <int> p;
int b[5001];
int ans[5001];
int done[5001];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) r[i]=-1;
    FOR(i, 1, n){
        if(a[i]==0) continue;///ignore all 0
        for(int x: p){
            if(is_perfect_square(a[x]*a[i])){
                uni(x, i);
                goto line0;
            }
        }
        p.pb(i);
        line0:;
    }
    FOR(i, 1, n) if(a[i]==0) b[i]=0;
    else b[i]=root(i);
    FOR(i, 1, n){
        int k=0;
        FOR(j, i, n){
            if(done[b[j]]!=i){
                done[b[j]]=i;
                if(b[j]) k++;
            }
            ans[max(1, k)]++;
        }
    }
    FOR(i, 1, n) write(ans[i]), putchar(" \n"[i==n]);
}