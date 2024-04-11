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
#include <numeric>
#define MOD 1000000007
using namespace std;
int n;
long long modpower(long long a, long long p){
    long long ret = 1;
    for(long long i = p; i > 0; i >>= 1){
        if(i & 1)ret = (ret * a) % MOD;
        a = (a * a) % MOD;
    }
    return ret;
}
long long calc(long long n, long long k){
    long long ret = 0, t = k;
    while(t <= n){
        ret += n / t;
        t *= k;
    }
    return ret;
}
bool isprime(int i){
    if(i < 2)return false;
    for(int d = 2; d * d <= i; d++)
        if(i % d == 0)return false;
    return true;
}
int main(){
    scanf("%d", &n);
    
    long long ret = 1;
    for(int i = 1; i <= 2 * n; i++)if(isprime(i)){
        int cur = calc(2 * n - 1, i) - calc(n - 1, i) - calc(n, i);
        ret = (ret * modpower(i, cur)) % MOD;
    }
    ret = (ret * 2 - n + MOD) % MOD;
    printf("%I64d\n", ret);
    return 0;
}