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
#define taskname "C"
int n;
int s[101];
int cnt[101];
int toa[101];
int f[101][201];
int zero=100;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n){
        read(s[i]);
        cnt[s[i]]++;
    }
    FOR(i, 0, 100) FOR(j, 0, zero*2) f[i][j]=-1;
    f[0][zero]=0;
    FFOR(i, 0, 100) FOR(j, -n, n) if(f[i][zero+j]>=0){
        if((cnt[i+1]==1)||(cnt[i+1]>2)){
            f[i+1][zero+j+1]=1;
            f[i+1][zero+j-1]=cnt[i+1]-1;
            if(cnt[i+1]>2) f[i+1][zero+j]=0;
        }
        else{
            f[i+1][zero+j]=0;
        }
    }
    if(f[100][zero]==-1) puts("NO");
    else{
        puts("YES");
        int x=0;
        DFOR(i, 100, 1){
            toa[i]=f[i][x+zero];
            if(f[i][x+zero]==1) x--;
            else if(f[i][x+zero]+1==cnt[i]) x++;
        }
        FOR(i, 1, n){
            if(toa[s[i]]){
                putchar('A');
                toa[s[i]]--;
            }
            else putchar('B');
        }
    }
}