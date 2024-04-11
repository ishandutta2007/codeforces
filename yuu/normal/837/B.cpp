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
int n, m;
char c[102][102];
bool done[102][102];
int cnt[256];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    cin>>n>>m;
    FOR(i, 1, n) FOR(j, 1, m){
        cin>>c[i][j];
        cnt[c[i][j]]++;
    }
    if((cnt['R']!=cnt['B'])||(cnt['B']!=cnt['G'])||(cnt['R']!=cnt['G'])){
        puts("NO");
        return 0;
    }
    if(n%3==0){
        int x=n/3;
        int xx=2*x;
        char q;
        char f, s, l;
        f=c[1][1];
        s=c[x+1][1];
        l=c[xx+1][1];
        if(f==s||s==l||l==f) goto line1;
        FOR(i, 1, x) FOR(j, 1, m) if(c[i][j]!=f) goto line1;
        FOR(i, x+1, xx) FOR(j, 1, m) if(c[i][j]!=s) goto line1;
        FOR(i, xx+1, n) FOR(j, 1, m) if(c[i][j]!=l) goto line1;
        puts("YES");
        return 0;
        line1:;
    }
    if(m%3==0){
        int x=m/3;
        int xx=2*x;
        char q;
        char f, s, l;
        f=c[1][1];
        s=c[1][x+1];
        l=c[1][xx+1];
        if(f==s||s==l||l==f) goto line2;
        FOR(j, 1, x) FOR(i, 1, n) if(c[i][j]!=f) goto line2;
        FOR(j, x+1, xx) FOR(i, 1, n) if(c[i][j]!=s) goto line2;
        FOR(j, xx+1, m) FOR(i, 1, n) if(c[i][j]!=l) goto line2;
        puts("YES");
        return 0;
        line2:;
    }
    puts("NO");
}