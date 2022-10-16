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
#define taskname "A"
int n1, n2, k1, k2;
int f[51][51][2];
bool done[51][51][2];
bool F(int n1, int n2, int turn){
    if(done[n1][n2][turn]) return f[n1][n2][turn];
    done[n1][n2][turn]=1;
    if(turn==0){
        DFOR(i, min(k1, n1), 1) if(!F(n1-i, n2, 1)) return f[n1][n2][turn]=1;
        return f[n1][n2][turn]=0;
    }
    else{
        DFOR(i, min(k2, n2), 1) if(!F(n1, n2-i, 0)) return f[n1][n2][turn]=1;
        return f[n1][n2][turn]=0;
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n1);
    read(n2);
    read(k1);
    read(k2);
//    if(F(n1, n2, 0)) puts("First");
//    else puts("Second");
    if(n1>n2) puts("First");
    else puts("Second");
}