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
#include <iostream>
#include <set>
#define base 1000000007
using namespace std;
int a[256];
int cnt[1001][256];
long long f[1001];
bool d[1001];
int n;
string s;
long long F(int u){
    if(d[u]) return f[u];
    d[u]=1;
    FOR(i, 'a', 'z'){
        if(cnt[u][i]&&u>a[i])
            goto line1;
    }
    f[u]=1;
    line1:;
    int temp[256];
    FOR(j, 'a', 'z')
        temp[j]=cnt[u][j];
    FOR(i, 1, u-1){
        temp[s[i]]--;
        FOR(j, 'a', 'z')
            if(temp[j]&&(u-i>a[j]))
                goto line2;
        f[u]=(f[u]+F(i))%base;
        line2:;
    }
    return f[u];
}
bool bscheck(int l){
    int temp[256];
    FOR(j, 'a', 'z')
        temp[j]=cnt[l-1][j];
    FOR(i, l, n){
        temp[s[i-l]]--;
        temp[s[i]]++;
        FOR(j, 'a', 'z')
            if(temp[j]&&(l>a[j]))
                goto line3;
        return 1;
        line3:;
    }
    return 0;
}
int bs(int l, int r){
    int m, res;
    while(l<=r){
        m=(l+r)/2;
        if(bscheck(m)){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int main(){
//    freopen("C.INP", "r", stdin);
    cin>>n>>s;
    s='0'+s;
    FOR(i, 1, n){
        FOR(j, 'a', 'z')
            cnt[i][j]=cnt[i-1][j];
        cnt[i][s[i]]++;
    }
    FOR(i, 'a', 'z')
        read(a[i]);
    writeln(F(n));
    writeln(bs(1, n));
    int res=1;
    int high=1, low=0;
    int temp[256];
    FOR(j, 'a', 'z') temp[j]=0;
    while(high<=n){
        temp[s[high]]++;
        FOR(j, 'a', 'z')
            if(temp[j]&&(high-low>a[j]))
                goto line4;
        high++;
        continue;
        line4:
        low=high-1;
        FOR(j, 'a', 'z') temp[j]=0;
        res++;
    }
    write(res);
}