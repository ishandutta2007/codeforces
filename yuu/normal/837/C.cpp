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
#define taskname "C"
int n, a, b;
int x[101], y[101];
bool good(int x1, int y1, int x2, int y2){
    if(x1+x2<=a) if(max(y1, y2)<=b) return 1;
    if(x1+y2<=a) if(max(y1, x2)<=b) return 1;
    if(y1+y2<=a) if(max(x1, x2)<=b) return 1;
    if(y1+x2<=a) if(max(x1, y2)<=b) return 1;
    if(x1+x2<=b) if(max(y1, y2)<=a) return 1;
    if(x1+y2<=b) if(max(y1, x2)<=a) return 1;
    if(y1+y2<=b) if(max(x1, x2)<=a) return 1;
    if(y1+x2<=b) if(max(x1, y2)<=a) return 1;
    return 0;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(a);
    read(b);
    int ans=0;
    FOR(i, 1, n){
        read(x[i]);
        read(y[i]);
    }
    FOR(i, 1, n) FOR(j, i+1, n) if(good(x[i], y[i], x[j], y[j])) ans=max(ans, x[i]*y[i]+x[j]*y[j]);
    write(ans);
}