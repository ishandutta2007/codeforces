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
#define taskname "B"
const ll inf=1LL<<50;
int n, k;
ll m;
ll t[46];
ll f[46][3001];
bool done[46][3001];
ll F(int x, int y){
    if(y<0) return inf;
    if(x==0){
        if(y==0) return 0;
        return inf;
    }
    if(done[x][y]) return f[x][y];
    done[x][y]=1;
    f[x][y]=F(x-1, y);
    FFOR(i, 1, k) f[x][y]=min(f[x][y], F(x-1, y-i)+t[i]);
    f[x][y]=min(f[x][y], F(x-1, y-k-1)+t[k]);
    return f[x][y];
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(k);
    read(m);
    FOR(i, 1, k) read(t[i]);
    sort(t+1, t+k+1);
    FOR(i, 1, k) t[i]+=t[i-1];
    DFOR(i, n*(k+1), 0){
        if(F(n, i)<=m){
            write(i);
            return 0;
        }
    }
}