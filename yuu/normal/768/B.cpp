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
vector <long long> v;
long long n, l ,r;
long long size(long long x){
    if(x<=1) return 1;
    else return 2LL*size(x/2)+1;
}
long long cnt(long long u){
    if(u<=1) return u;
    return 2LL*cnt(u/2)+u%2;
}
long long build(long long u, long long x){
    if(x<=0) return 0;
    if(u<=1) return u;
    else{
        if(size(u)==x) return cnt(u);
        long long temp=size(u/2);
        if(temp>=x)
            return build(u/2, x);
        else{
            long long res=cnt(u/2)+u%2;
            x-=temp+1;
            if(x>0)
                return res+build(u/2, x);
            else return res;
        }
    }
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(l);
    read(r);
    writeln(build(n, r)-build(n, l-1));
}