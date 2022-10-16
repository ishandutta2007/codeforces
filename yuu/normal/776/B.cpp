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
bool prime[1000001];
int n;
int main(){
    #ifdef JohnTitor
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // JohnTitor
    read(n);
    if(n<=2){
        writeln(1);
        FOR(i, 1, n)
            write(1), putchar(' ');
    }
    else{
        n++;
        prime[2]=1;
        for(int i=3; i<=n; i+=2) prime[i]=1;
        for(int i=3; i*i<=n; i+=2){
            if(prime[i]){
                for(int j=i+i; j<=n; j+=i)
                    prime[j]=0;
            }
        }
        writeln(2);
        FOR(i, 2, n){
            if(prime[i])
                putchar('1');
            else putchar('2');
            putchar(' ');
        }
    }
}