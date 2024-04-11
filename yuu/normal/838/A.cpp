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
#define taskname "A"
int n, m;
int f[5001][5001];
char c[5001][5001];
inline int sum(int x, int y, int u, int v){
    return f[u][v]-f[u][y-1]-f[x-1][v]+f[x-1][y-1];
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i, 1, n) FOR(j, 1, m){
        cin>>c[i][j];
        c[i][j]-='0';
    }
    FOR(i, 1, 5000) FOR(j, 1, 5000) f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+c[i][j];
    int ans=5000*5000;
    DFOR(k, 2500, 2){
        int i=1;
        int res=0;
        int sq=k*k;
        int t=0;
        do{
            int j=1;
            do{
                t=sum(i, j, i+k-1, j+k-1);
                res+=min(t, sq-t);
                j+=k;
            }
            while(j<=m);
            i+=k;
        }
        while(i<=n);
        ans=min(ans, res);
    }
    writeln(ans);
}