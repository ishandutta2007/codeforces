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
#define taskname "D"
long long ke[2000001];
long long x;
int k=0;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(x);
    x*=6;
    long long i=1;
    while(true){
        long long j=(x+i*(i*i-1))/(i*(i+1)*3);
        if(i>j) break;
        if(j*(i*(i+1)*3)==x+i*(i*i-1)){
            ke[i]=j;
            k+=2;
            if(i==j){
                k--;
                break;
            }
        }
        i++;
    }
    writeln(k);
    FOR(j, 1, i){
        if(ke[j]){
            write(j);
            putchar(' ');
            writeln(ke[j]);
        }
    }
    DFOR(j, i, 1){
        if(ke[j]){
            if(ke[j]!=j){
                write(ke[j]);
                putchar(' ');
                writeln(j);
            }
        }
    }
 
}