#include <stdio.h>
using namespace std;
int n;
bool isprime(int u){
    for(int i=2; i*i<=u; i++){
        if(u%i==0) return 0;
    }
    return 1;
}
int main(){
    scanf("%i", &n);
    if(isprime(n)) printf("1");
    else if(n%2==0)printf("2");
    else if(isprime(n-2)) printf("2");
    else printf("3");
}