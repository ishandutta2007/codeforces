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
int n, m, ans;
int h[100001];
int t[100001];
int ft[100001];
int cnth[100001];
int cntt[100001];
int old=0;
int get(int u){
    int res=0;
    for(; u>0; u-=u&(-u))
        res+=ft[u];
    return res;
}
void update(int u, int x){
    for(; u<=n; u+=u&(-u))
        ft[u]+=x;
}
bool cmp(int a, int b){
    return (h[a]<h[b])||(h[a]==h[b]&&a>b);
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n){
        read(h[i]);
        t[i]=i;
    }
    sort(t+1, t+n+1, cmp);
    int old=h[t[1]]-1;
    FOR(i, 1, n){
        if(h[t[i]]==old)
            h[t[i]]=m;
        else{
            old=h[t[i]];
            h[t[i]]=++m;
        }
    }
    FOR(i, 1, n)
        t[i]=h[i];
    sort(t+1, t+n+1);
    FOR(i, 1, n){
        if(cntt[h[i]]){
            cntt[h[i]]--;
            update(h[i], -1);
        }
        else{
            cnth[h[i]]++;
            update(h[i], 1);
        }
        if(cnth[t[i]]){
            cnth[t[i]]--;
            update(t[i], -1);
        }
        else{
            cntt[t[i]]++;
            update(t[i], 1);
        }
        if(get(n)==0) ans++;
    }
    write(ans);
}