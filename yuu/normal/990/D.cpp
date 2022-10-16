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
#define taskname "D"
int n, a, b;
bool inv;
bool c[1001][1001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(a);
    read(b);
    if(a==1){
        swap(a, b);
        inv=1;
    }
    if(b>1){
        puts("NO");
        return 0;
    }
    if((a==1)&&((n==3)||(n==2))){
        puts("NO");
        return 0;
    }
    puts("YES");
    FOR(i, 2, n-a+1) c[i][i-1]=c[i-1][i]=1;
    if(inv){
        FOR(i, 1, n) c[i][i]=1;
        FOR(i, 1, n){
            FOR(j, 1, n){
                putchar("10"[c[i][j]]);
            }
            putchar('\n');
        }
    }
    else{
        FOR(i, 1, n){
            FOR(j, 1, n){
                putchar("01"[c[i][j]]);
            }
            putchar('\n');
        }
    }
}