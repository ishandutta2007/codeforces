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
#include <iostream>
#include <algorithm>
using namespace std;
string s, m;
int n;
int pv, mina, maxa;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    cin>>s>>m;
    sort(s.begin(), s.end());
    sort(m.begin(), m.end());
    s='a'+s;
    m='a'+m;
    pv=1;
    FOR(i, 1, n){
        while(pv<=n&&m[pv]<=s[i])
            pv++;
        if(pv>n)
            break;
        else pv++;
        maxa++;
    }
    pv=1;
    int pp=n;
    DFOR(i, n, 1){
        if(s[i]>m[pp]){
            pv++;
            mina++;
        }
        else
            pp--;
    }
    printf("%d\n%d", mina, maxa);
}