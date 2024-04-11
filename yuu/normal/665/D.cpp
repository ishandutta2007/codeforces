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
#define taskname "D"
int n;
int a[1001];
bool p[2000001];
int c[3];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n){
        read(a[i]);
        if(a[i]<=2) c[a[i]]++;
    }
    FOR(i, 2, 2000000) p[i]=1;
    FOR(i, 2, 2000000) if(p[i]) for(int j=i+i; j<=2000000; j+=i) p[j]=0;
    if(c[1]>=2){
        int r=0;
        FOR(i, 1, n) if((a[i]>1)&&(p[a[i]+1])){
            r=a[i];
            break;
        }
        writeln(c[1]+(r!=0));
        if(r){
            write(r);
            putchar(' ');
        }
        FOR(i, 1, c[1]){
            write(1);
            putchar(' ');
        }
        return 0;
    }
    FOR(i, 1, n) FOR(j, i+1, n) if(p[a[i]+a[j]]){
        writeln(2);
        write(a[i]);
        putchar(' ');
        write(a[j]);
        return 0;
    }
    FOR(i, 1, n){
        writeln(1);
        write(a[i]);
        return 0;
    }
}