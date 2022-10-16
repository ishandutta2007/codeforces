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
#include <deque>
using namespace std;
deque <int> dq;
long long a[400001];
long long n;
long long ans=0;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n)
        read(a[i]);
    FOR(i, 1, n)
        a[n+i]=a[i];
    FOR(i, 1, n-1){
        while((!dq.empty())&&(a[dq.back()]>a[i]))
            dq.pop_back();
        dq.push_back(i);
    }
    FOR(i, 1, n){
        while((!dq.empty())&&(dq.front()<i))
            dq.pop_front();
        while((!dq.empty())&&(a[dq.back()]>a[i+n-1]))
            dq.pop_back();
        dq.push_back(i+n-1);
        ans=max(ans, n*a[dq.front()]+dq.front()-i);
    }
    writeln(ans);
}