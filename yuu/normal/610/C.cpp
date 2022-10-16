#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<k; i++)
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
int n;
using namespace std;
char a[1<<9][1<<9];
void solve(int n){
    if(!n){
        a[0][0]='+';
        return ;
    }
    solve(n-1);
    int mid=1<<(n-1);
    FOR(i, mid, (1<<n))
        FOR(j, 0, mid)
            a[i][j]=a[i-mid][j];
    FOR(i, 0, mid)
        FOR(j,mid,(1<<n))
            a[i][j]=a[i][j-mid];
    FOR(i, mid,(1<<n))
        FOR(j, mid, (1<<n))
            a[i][j]='+'+'*'-a[i-mid][j-mid];
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    solve(n);
    FOR(i, 0, 1<<n){
        FOR(j, 0, 1<<n)
            putchar(a[i][j]);
        putchar('\n');
    }
}