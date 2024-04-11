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
#define inf 100000000
#define opt(x, y) (x=(x<(y)?x:(y)))
using namespace std;
int n, m;
string s;
struct str{
    int todigit, toalpha, tosymbol;
} a[51];
int ans=inf;
int main(){
    read(n);
    read(m);
    FOR(i, 1, n){
        cin>>s;
        a[i].toalpha=a[i].todigit=a[i].tosymbol=inf;
        int length=0;
        for(int j=0; j<m; j++){
            if(isalpha(s[j]))
                opt(a[i].toalpha, length);
            else if(isdigit(s[j]))
                opt(a[i].todigit, length);
            else opt(a[i].tosymbol, length);
            length++;
        }
        length=1;
        for(int j=m-1; j>=0; j--){
            if(isalpha(s[j]))
                opt(a[i].toalpha, length);
            else if(isdigit(s[j]))
                opt(a[i].todigit, length);
            else opt(a[i].tosymbol, length);
            length++;
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            if(j==i) continue;
            FOR(k, 1, n){
                if(k==i||k==j) continue;
                opt(ans, a[i].toalpha+a[j].todigit+a[k].tosymbol);
            }
        }
    }
    write(ans);
}