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
#define taskname "B"
/// 4, 8, 15, 16, 23,  42
/// 2^2, 2^3, 3*5, 2^4, 23, 2*3*7
int num[]={0, 4, 8, 15, 16, 23, 42};
int ans[7];
set <int> s[7];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    printf("? 1 2\n");
    fflush(stdout);
    int a12, a34, a13;
    scanf("%d", &a12);
    printf("? 3 4\n");
    fflush(stdout);
    scanf("%d", &a34);
    printf("? 1 3\n");
    fflush(stdout);
    scanf("%d", &a13);
    FOR(i, 1, 6) FOR(j, 1, 6) s[i].insert(num[j]);
    FOR(i, 1, 6){
        bool have=0;
        FOR(j, 1, 6) if(j!=i) if(num[i]*num[j]==a12) have=1;
        if(!have) s[1].erase(num[i]);
    }
    FOR(i, 1, 6){
        bool have=0;
        FOR(j, 1, 6) if(j!=i) if(num[i]*num[j]==a13) have=1;
        if(!have) s[1].erase(num[i]);
    }
    FOR(i, 1, 6){
        bool have=0;
        FOR(j, 1, 6) if(j!=i) if(num[i]*num[j]==a13) have=1;
        if(!have) s[3].erase(num[i]);
    }
    FOR(i, 1, 6){
        bool have=0;
        FOR(j, 1, 6) if(j!=i) if(num[i]*num[j]==a34) have=1;
        if(!have) s[3].erase(num[i]);
    }
    ans[1]=*s[1].begin();
    ans[2]=a12/ans[1];
    ans[3]=*s[3].begin();
    ans[4]=a34/ans[3];
    int a55;
    printf("? 5 5\n");
    fflush(stdout);
    scanf("%d", &a55);
    FOR(i, 1, 6) if(num[i]*num[i]==a55) ans[5]=num[i];
    FOR(i, 1, 5) s[6].erase(ans[i]);
    ans[6]=*s[6].begin();
    printf("!");
    FOR(i, 1, 6) printf(" %d", ans[i]);
    puts("\n");
    fflush(stdout);
}