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
int n, l;
int k[51];
int s[51];
int a, b;
int main(){
    read(n);
    read(l);
    FOR(i, 1, n)
        read(k[i]);
    FOR(i, 1, n)
        read(s[i]);
    k[0]=k[n];
    FOR(spin, 0, n){
        s[0]=s[n];
        FOR(i, 1, n){
            if(s[i]<s[i-1])
                a=s[i]+l-s[i-1];
            else a=s[i]-s[i-1];
            if(k[i]<k[i-1])
                b=k[i]+l-k[i-1];
            else b=k[i]-k[i-1];
            if(a!=b) goto line1;
        }
        puts("YES");
        return 0;
        line1:;
        DFOR(i, n, 1)
            s[i]=s[i-1];
    }
    puts("NO");
}