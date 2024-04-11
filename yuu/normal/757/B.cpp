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
int cnt[100001];
int n, a;
#define max(a, b) (a>b?a:b)
int main(){
    read(n);
    FOR(i, 1, n){
        read(a);
        int j=2;
        while(j*j<=a){
            if(a%j==0){
                cnt[j]++;
                while(a%j==0)
                    a/=j;
            }
            j++;
        }
        if(a>1) cnt[a]++;
    }
    int ans=1;
    FOR(i, 1, 100000)
        ans=max(ans, cnt[i]);
    write(ans);
}