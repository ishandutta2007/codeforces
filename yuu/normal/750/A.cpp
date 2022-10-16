#include <stdio.h>
#include <locale>
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while(!isdigit(c=getchar())&&c!='-');
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
template <typename T> inline writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline writeln(T x){
    write(x);
    putchar('\n');
}
int main(){
    int n, k;
    read(n);
    read(k);
    k=240-k;
    int i=0;
    while(k>=(i+1)*5&&i<n){
        i++;
        k-=i*5;
    }
    write(i);
}