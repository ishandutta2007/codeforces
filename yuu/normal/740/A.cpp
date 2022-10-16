#include <stdio.h>
#include <algorithm>
using namespace std;
long long ans=9999999999999;
long long n, a, b, c;
int main(){
    scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
    for(long long i=0; i<=3; i++){
        for(long long j=0; j<=3; j++)
            for(long long k=0; k<=3; k++){
                if((n+i+j*2+k*3)%4==0){
                    ans=min(ans, a*i+b*j+c*k);
                }
            }
    }
    printf("%I64d", ans);
}