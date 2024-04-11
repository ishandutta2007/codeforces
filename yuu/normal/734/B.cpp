#include <stdio.h>
int k2, k3, k5, k6;
int ans=0;
int main(){
    scanf("%i%i%i%i", &k2, &k3, &k5, &k6);
    int x=k5<k6?k5:k6;
    x=x<k2?x:k2;
    k2-=x;
    k3=k3>k2?k2:k3;
    printf("%d", x*256+k3*32);
}