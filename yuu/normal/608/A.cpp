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
int k[1001];
int n, s;
int a, b;
pair <int, int> p[111];
int f;
int main(){
//    freopen("A.INP", "r", stdin);
    read(n);
    read(f);
    FOR(i, 1, n){
        read(p[i].f);
        read(p[i].s);
    }
    s=0;
    sort(p+1, p+n+1);
    p[n+1]=make_pair(0, 0);
    DFOR(i, n+1, 0){
        s+=f-p[i].f;
        f=p[i].f;
        if(s<=p[i].s)
            s=p[i].s;
    }
    write(s);
}