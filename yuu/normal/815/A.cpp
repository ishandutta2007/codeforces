#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
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
int g[101][101];
int a[101];
int ans=-1;
vector <int> v;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    FOR(i, 1, n) FOR(j, 1, m) read(g[i][j]);
    FOR(s, 0, g[1][1]){
        int res=0;
        FOR(i, 1, n){
            if(g[i][1]<s) goto line2;
            else a[i]=g[i][1]-s;
        }
        FOR(j, 2, m){
            int c=g[1][j]-a[1];
            if(c<0) goto line1;
            FOR(i, 2, n) if(g[i][j]-a[i]!=c) goto line1;
        }
        FOR(i, 1, n) res+=a[i];
        FOR(i, 1, m) res+=g[1][i]-a[1];
        if(ans==-1||res<ans){
            ans=res;
            v.clear();
            FOR(i, 1, n) v.pb(a[i]);
            FOR(i, 1, m) v.pb(g[1][i]-a[1]);
        }
        line1:;
    }
    line2:;
    writeln(ans);
    if(ans!=-1){
        DFOR(i, m, 1){
            FOR(j, 1, v.back()) printf("col %d\n", i);
            v.pop_back();
        }
        DFOR(i, n, 1){
            FOR(j, 1, v.back()) printf("row %d\n", i);
            v.pop_back();
        }
    }
}