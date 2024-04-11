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
#define taskname "E"
int n, m;
bool c[3002][3002];
int l[3002][3002];
int r[3002][3002];
pair <int, int> v[3002];
vector <int> rmv[3002];
int q;
ll ans=0;
int ft[3002];
void update(int u, int x){
    for(; u<=q; u+=u&-u) ft[u]+=x;
}
int get(int u){
    int res=0;
    for(; u>0; u-=u&-u) res+=ft[u];
    return res;
}
int get(int l, int r){
    return get(r)-get(l-1);
}
void solve_line(){
    FOR(i, 1, q+1){
        ft[i]=0;
        rmv[i].clear();
    }
    FOR(i, 1, q){
        for(int u: rmv[i]) update(u, -1);
        update(i, 1);
        rmv[min(q, i+v[i].first-1)+1].pb(i);
        ans+=get(max(1, i-v[i].second+1), i);
    }
    q=0;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    {
        char ch;
        FOR(i, 1, n) FOR(j, 1, m){
            while(ch=getchar()) if((ch=='z')||(ch=='.')) break;
            c[i][j]=(ch=='z');
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(c[i][j]) l[i][j]=l[i][j-1]+1;
            else l[i][j]=0;
        }
        DFOR(j, m, 1){
            if(c[i][j]) r[i][j]=r[i][j+1]+1;
            else r[i][j]=0;
        }
    }
    FOR(d, 2, n+m){
        int j;
        FOR(i, max(1, d-m), min(n, d-1)){
            j=d-i;
            if(!c[i][j]){
                if(q) solve_line();
            }
            else{
                q++;
                v[q]=mp(l[i][j], r[i][j]);
            }
        }
        if(q) solve_line();
    }
    writeln(ans);
}