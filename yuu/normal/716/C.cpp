#include <stdio.h>
long long k, a;
long long x=2;
int main(){
    int n;
    scanf("%i", &n);
    for(k=1; k<=n; k++){
        printf("%I64d\n", k*(k+1)*(k+1)-x/k);
        x=k*(k+1);
    }
}