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
int n;
int a[200001];
int b[200001];
int main(){
    read(n);
    FOR(i, 1, n)
        read(a[i]);
    int i;
    for(i=1; i*2<=n; i++){
        if(i%2==0)
            b[i]=a[i];
        else b[i]=a[n-i+1];
    }
    for(i=n; i>n/2; i--){
        if((n-i)%2==0)
            b[i]=a[n-i+1];
        else b[i]=a[i];
    }
    FOR(i, 1, n)
        write(b[i]), putchar(' ');
}