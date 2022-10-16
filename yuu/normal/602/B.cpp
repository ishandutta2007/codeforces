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
deque <int> dmin;
deque <int> dmax;
int pos=1;
int n;
int a[100001];
int ans;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n)
        read(a[i]);
    FOR(i, 1, n){
        while((!dmin.empty())&&(a[i]<=a[dmin.back()]))
            dmin.pop_back();
        dmin.push_back(i);
        while((!dmax.empty())&&(a[i]>=a[dmax.back()]))
            dmax.pop_back();
        dmax.push_back(i);
        while(a[dmax.front()]-a[dmin.front()]>1){
            if(dmax.front()<dmin.front()){
                pos=dmax.front()+1;
                dmax.pop_front();
            }
            else{
                pos=dmin.front()+1;
                dmin.pop_front();
            }
        }
        ans=max(ans, i-pos+1);
    }
    write(ans);
}