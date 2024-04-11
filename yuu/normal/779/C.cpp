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
pair<int, int> p[200001];
int n, k;
int ans=0;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second-a.first>b.second-b.first;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(k);
    FOR(i, 1, n)
        read(p[i].first);
    FOR(i, 1, n)
        read(p[i].second);
    sort(p+1, p+n+1, cmp);
    int i=1;
    while(i<=k){
        ans+=p[i].first;
        i++;
    }
    while(i<=n&&p[i].second>p[i].first){
        ans+=p[i].first;
        i++;
    }
    FOR(j, i, n)
        ans+=p[j].second;
    write(ans);
}