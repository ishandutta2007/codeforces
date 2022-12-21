#include<stdio.h>
#include<algorithm>
#define P 1000000007
using namespace std;
int i,j,k,l,s,m;
long long n;
inline int quick(int o,int p) {
    int s=1;
    while (p) {
        if (p&1) s=1ll*o*s%P;
        o=1ll*o*o%P;
        p>>=1;
    }
    return s;
}
inline void work(int o) {
    printf("%d\n",(quick(2,n-1)+quick(2,(2*n-1)))%P);
}
int main() {
    scanf("%I64d",&n);
    if (n==0) return puts("1"),0;
    n%=(P-1); 
    work(n);
}