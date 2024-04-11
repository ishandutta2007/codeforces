#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long n,k;

int main(){
    cin >> n >> k;

    long long i = max(1LL,(long long)sqrt(k * 2LL) - 10);
    while(i * (i - 1) / 2 < k) i++;
    if(i > n){
        printf("Impossible");
    }else{
        if(i * (i - 1) / 2 == k){
            for(long long j = 1;j <= i;j++){
                putchar('(');
            }
            for(long long j = 1;j <= i;j++){
                putchar(')');
            }
            for(long long j = i + 1;j <= n;j++){
                printf("()");
            }
            puts("");
        }else{
            long long d = i * (i - 1) / 2 - k;
            for(long long j = 1;j <= i - 1;j++){
                putchar('(');
            }
            for(long long j = 1;j <= i - 1;j++){
                putchar(')');
                if(j == d){
                    printf("()");
                }
            }
            for(long long j = i + 1;j <= n;j++){
                printf("()");
            }
            puts("");
        }
    }
    return 0;
}