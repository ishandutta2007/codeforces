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
#define taskname "B"
#include <vector>
using namespace std;
int n, m;
int f[100001];
int b[100001];
vector <int> cnt[100001];
int a[100001];
bool able;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    FOR(i, 1, n){
        read(f[i]);
        cnt[f[i]].push_back(i);
    }
    FOR(i, 1, m){
        read(b[i]);
        if(cnt[b[i]].empty()){
            puts("Impossible");
            return 0;
        }
        else if(cnt[b[i]].size()>1)
            able=1;
        else
            a[i]=cnt[b[i]][0];
    }
    if(able)
        puts("Ambiguity");
    else{
        puts("Possible");
        FOR(i, 1, m)
            write(a[i]), putchar(' ');
    }
}