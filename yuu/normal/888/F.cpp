#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "circle"
int n;
int x[1001];
int c[1001][1001];
ll f1[1001][1001];
ll f0[1001][1001];
bool d1[1001][1001];
bool d0[1001][1001];
ll F1(int, int);
const ll base=1000000007;
inline void update(ll &a, ll b){
    a+=b;
    a%=base;
}
ll F0(int u, int v){
    if(d0[u][v]) return f0[u][v];
    d0[u][v]=1;
    if(u==v) return f0[u][v]=1;
    f0[u][v]=F1(u+1, v);
    FFOR(i, u+1, v) if(c[u][i]) update(f0[u][v], F0(u, i)*F0(i, v));
    return f0[u][v];
}
ll F1(int u, int v){
    if(d1[u][v]) return f1[u][v];
    d1[u][v]=1;
    if(u==v) return f1[u][v]=1;
    FOR(i, u+1, v) if(c[u][i]) update(f1[u][v], F0(u, i)*F1(i, v));
    return f1[u][v];
}
void make_edge(){
    FFOR(i, 0, n) read(x[i]);
    FFOR(i, 0, n) FOR(j, i+1, n) if(__gcd(x[i], x[j])>1) c[i][j]=c[j][i]=1;
}
void read_edge(){
    FFOR(i, 0, n) FFOR(j, 0, n) read(c[i][j]);
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
//    freopen(taskname".inp", "r", stdin);
//    freopen(taskname".out", "w", stdout);
    read(n);
//    make_edge();
    read_edge();
    writeln(F1(0, n-1));
}