#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "E"
int n, q;
int a[300002];
int first[300002][19];
int nx[300002][19];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(q);
    FOR(i, 1, n) read(a[i]);
    FFOR(j, 0, 19) first[n+1][j]=n+1;
    FFOR(j, 0, 19) nx[n+1][j]=n+1;
    DFOR(i, n, 1){
        FFOR(j, 0, 19) if(bit(a[i+1], j)==1) nx[i][j]=i+1; else nx[i][j]=nx[i+1][j];
        FFOR(j, 0, 19) if(bit(a[i], j)) first[i][j]=i; else first[i][j]=n+1;
        FFOR(j, 0, 19) FFOR(k, 0, 19) if(bit(a[i], k)) first[i][j]=min(first[i][j], first[nx[i][k]][j]);
    }
    {
        int x, y;
        FOR(qr, 1, q){
            read(x);
            read(y);
            bool good=0;
            FFOR(i, 0, 19) if(bit(a[y], i)) if(first[x][i]<=y){
                good=1;
                break;
            }
            if(good) puts("Shi");
            else puts("Fou");
        }
    }
}