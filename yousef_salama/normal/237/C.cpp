#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
using namespace std;
int a, b, K, sum[1000005];
bool sieve[1000005];
bool check(int len){
    for(int i = a; i <= b - len + 1; i++){
        if(sum[i + len - 1] - sum[i - 1] < K)return false;
    }
    return true;
}
int main(){
    sieve[0] = sieve[1] = true;
    for(long long i = 2; i <= 1000000; i++){
        if(!sieve[i])
        for(long long j = i * i; j <= 1000000; j += i)
            sieve[j] = true;
    }
    sum[0] = 0;
    for(int i = 1; i <= 1000000; i++)
        sum[i] = sum[i - 1] + (!sieve[i]);

    scanf("%d %d %d", &a, &b, &K);
    int L = 1, R = (b - a + 1);
    while(L < R){
        int mid = (L + R) / 2;
        
        if(check(mid))R = mid;
        else L = mid + 1;
    }
    if(check(L))printf("%d\n", L);
    else printf("-1\n");
    return 0;
}