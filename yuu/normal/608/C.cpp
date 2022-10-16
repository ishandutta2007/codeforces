#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#include <algorithm>
#define f first
#define s second
using namespace std;
pair<int, int> b[100001];
bool d[100001];
int f[100001];
int n;
int bs(int x){
    int l=1, r=n;
    int res=0;
    while(l<=r){
        int m=(l+r)/2;
        if(b[m].f<x){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int F(int i){
    if(d[i]) return f[i];
    d[i]=1;
    int l=bs(b[i].f-b[i].s);
    return f[i]=F(l)+1;
}
int main(){
//    freopen("C.INP", "r", stdin);
    d[0]=1;
    read(n);
    FOR(i, 1, n){
        read(b[i].f);
        read(b[i].s);
    }
    sort(b+1, b+n+1);
    int ans=0;
    DFOR(i, n, 1)
        ans=max(ans, F(i));
    write(n-ans);
}