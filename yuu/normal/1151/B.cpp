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
int a[501][501];
vector <int> v[501];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FOR(i, 1, n) FOR(j, 1, m){
        read(a[i][j]);
        if((v[i].empty())||(a[i][j]!=a[i][v[i].back()])) v[i].pb(j);
    }
    int base=0;
    FOR(i, 1, n) base^=a[i][1];
    if(base){
        puts("TAK");
        FOR(i, 1, n){
            write(1);
            putchar(" \n"[i==n]);
        }
        return 0;
    }
    FOR(i, 1, n) if(v[i].size()>1){
        puts("TAK");
        FFOR(j, 1, i){
            write(1);
            putchar(' ');
        }
        write(v[i][1]);
        putchar(" \n"[i==n]);
        FOR(j, i+1, n){
            write(1);
            putchar(" \n"[j==n]);
        }
        return 0;
    }
    puts("NIE");
}