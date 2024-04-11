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
#define taskname "E"
#include <math.h>
#include <algorithm>
using namespace std;
long long n;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    long long x, m;
    long long l=1, r=1000000000;
    while(l<=r){
        long long mid=(l+r)/2;
        if(mid*(mid+1)*3>=n){
            x=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    n-=x*(x-1)*3;
    pair <long long, long long> ans=make_pair((x-1)*2, 0);
    if(n==0) goto line1;
    //____________________________________________________________________________
    n--;
    ans.first++;
    ans.second+=2;
    //____________________________________________________________________________
    m=min(x-1, n);
    ans.first-=m;
    ans.second+=m*2;
    n-=m;
    if(n==0) goto line1;
    //____________________________________________________________________________
    m=min(x, n);
    ans.first-=m*2;
    n-=m;
    if(n==0) goto line1;
    //____________________________________________________________________________
    m=min(x, n);
    ans.first-=m;
    ans.second-=m*2;
    n-=m;
    if(n==0) goto line1;
    //____________________________________________________________________________
    m=min(x, n);
    ans.first+=m;
    ans.second-=m*2;
    n-=m;
    if(n==0) goto line1;
    //____________________________________________________________________________
    m=min(x, n);
    ans.first+=m*2;
    n-=m;
    if(n==0) goto line1;
    //____________________________________________________________________________
    m=min(x, n);
    ans.first+=m;
    ans.second+=m*2;
    n-=m;
    if(n==0) goto line1;
    //____________________________________________________________________________
    line1:;
    write(ans.first);
    putchar(' ');
    write(ans.second);
}