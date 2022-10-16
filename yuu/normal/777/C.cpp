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
#define taskname "C"
#include <algorithm>
using namespace std;
int h[1000001][2];
int a[1000001][2];
int ans[1000001];
int n, m, k, l, r;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    FOR(i, 1, n){
        int temp=i%2;
        int opp=1-temp;
        FOR(j, 1, m){
            read(a[j][temp]);
            if(a[j][temp]>=a[j][opp])
                h[j][temp]=h[j][opp]+1;
            else h[j][temp]=1;
            ans[i]=max(ans[i], h[j][temp]);
        }
    }
    read(k);
    FOR(i, 1, k){
        read(l);
        read(r);
        if(l+ans[r]>r)
            puts("Yes");
        else puts("No");
    }
}