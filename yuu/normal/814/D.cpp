#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define sqr(x) ((x)*(x))
#define dist(x1, y1, x2, y2) (sqrt(sqr(x1-x2)+sqr(y1-y2)))
typedef long double ld;
const ld pi=acos((ld)(0))*2;
struct circle{
    ld x, y, r;
    ld s;
    bool inside(circle C){
        if(dist(x, y, C.x, C.y)>=C.r) return 0;
        return C.s>s;
    }
} c[1001];
int n;
ld f[1001][2][2];
bool done[1001][2][2];
vector <int> g[1001];
ld F(int u, int a, int b){
    if(done[u][a][b]) return f[u][a][b];
    done[u][a][b]=1;
    if(a==0){
        if(b==0){
            for(int v: g[u]) f[u][a][b]+=max(F(v, 1-a, b)+c[v].s, F(v, a, 1-b)+c[v].s);
            return f[u][a][b];
        }
        else{
            for(int v: g[u]) f[u][a][b]+=max(F(v, 1-a, b)+c[v].s, F(v, a, 1-b)-c[v].s);
            return f[u][a][b];
        }
    }
    else{
        if(b==0){
            for(int v: g[u]) f[u][a][b]+=max(F(v, 1-a, b)-c[v].s, F(v, a, 1-b)+c[v].s);
            return f[u][a][b];
        }
        else{
            for(int v: g[u]) f[u][a][b]+=max(F(v, 1-a, b)-c[v].s, F(v, a, 1-b)-c[v].s);
            return f[u][a][b];
        }
    }
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    FOR(i, 1, n){
        cin>>c[i].x>>c[i].y>>c[i].r;
        c[i].s=sqr(c[i].r)*pi;
    }
    FOR(i, 1, n){
        int pos=0;
        FOR(j, 1, n){
            if(i==j) continue;
            if(c[i].inside(c[j])){
                if(pos==0) pos=j;
                else if(c[pos].s>c[j].s) pos=j;
            }
        }
        g[pos].pb(i);
    }
    cout<<setprecision(15)<<fixed<<F(0, 0, 0);
}