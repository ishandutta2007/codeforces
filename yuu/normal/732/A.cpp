#include <stdio.h>
int main(){
    int r, k, i;
    scanf("%i%i", &k, &r);
    for(i=1; i<=9; i++)
        if(k*i%10==r||k*i%10==0) break;
    printf("%d", i);
}