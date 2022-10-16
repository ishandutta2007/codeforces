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
#define taskname "E"
const int inf=10000;
int f[101][2001];
bool c[101][2001];
int n, m;
struct item{
    int t, d, p, id;
    bool operator <(item x){
        return d<x.d;
    }
} v[101];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n){
        read(v[i].t);
        read(v[i].d);
        read(v[i].p);
        m+=v[i].t;
        v[i].id=i;
    }
    sort(v+1, v+n+1);
    FOR(i, 0, n) FOR(j, 0, m) f[i][j]=-inf;
    f[0][0]=0;
    FOR(i, 1, n){
        FOR(j, 0, m-v[i].t){
            if((j+v[i].t<v[i].d)&&f[i][j+v[i].t]<f[i-1][j]+v[i].p){
                f[i][j+v[i].t]=f[i-1][j]+v[i].p;
                c[i][j+v[i].t]=1;
            }
        }
        FOR(j, 0, m) if(f[i][j]<f[i-1][j]){
            f[i][j]=f[i-1][j];
            c[i][j]=0;
        }
    }
    int best=0;
    FOR(i, 1, m) if(f[n][i]>f[n][best]) best=i;
    writeln(f[n][best]);
    vector <int> ans;
    DFOR(i, n, 1){
        if(c[i][best]){
            ans.pb(v[i].id);
            best-=v[i].t;
        }
    }
    writeln(ans.size());
    reverse(ans.begin(), ans.end());
    FFOR(i, 0, ans.size()){
        if(i) putchar(' ');
        write(ans[i]);
    }
}