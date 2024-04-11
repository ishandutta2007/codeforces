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
#define taskname "B"
int n, m;
char c[1002][1002];
bool good[1002][1002];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, n) FOR(j, 1, m){
        while(c[i][j]=getchar()){
            if(c[i][j]=='#') break;
            if(c[i][j]=='.') break;
        }
    }
    FOR(i, 1, n) FOR(j, 1, m){
        FOR(x, i-1, i+1) FOR(y, j-1, j+1){
            if(x==i&&y==j) continue;
            if(c[x][y]!='#') goto line0;
        }
        FOR(x, i-1, i+1) FOR(y, j-1, j+1){
            if(x==i&&y==j) continue;
            good[x][y]=1;
        }
        line0:;
    }
    FOR(i, 1, n) FOR(j, 1, m) if((c[i][j]=='#')&&(!good[i][j])){
        puts("NO");
        return 0;
    }
    puts("YES");
}