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
#define taskname "869E"
const ll base=999727999;
int n, m, q;
ll ft[2501][2501];
void update(int u, int v, ll a){
    for(int x=u; x<=n; x+=x&-x) for(int y=v; y<=m; y+=y&-y) ft[x][y]=(ft[x][y]+a)%base;
}
ll get(int u, int v){
    ll res=0;
    for(int x=u; x>0; x-=x&-x) for(int y=v; y>0; y-=y&-y) res+=ft[x][y];
    return res%base;
}
void update(int x0, int y0, int x1, int y1, ll d){
    update(x0, y0, d);
    update(x0, y1+1, -d);
    update(x1+1, y0, -d);
    update(x1+1, y1+1, d);
}
map <pair <int, int>, ll> M;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(q);
    {
        int o, x0, y0, x1, y1;
        const ll a=37;
        const char* ans[]={"No", "Yes"};
        ll p=1;
        FOR(i, 1, q){
            read(o);
            read(x0);
            read(y0);
            read(x1);
            read(y1);
            if(o==3){
                puts(ans[(get(x0, y0)-get(x1, y1))%base==0]);
            }
            else{
                if(o==2){
                    update(x0, y0, x1, y1, -M[mp(x0, y0)]);
                }
                else{
                    M[mp(x0, y0)]=p;
                    update(x0, y0, x1, y1, M[mp(x0, y0)]);
                }
            }
            p=(p*a)%base;
        }
    }
}