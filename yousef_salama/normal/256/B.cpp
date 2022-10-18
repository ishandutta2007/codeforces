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
using namespace std;
int n, x, y, c;
long long solve(long long a, long long b, long long t){
    if(a == 0 || b == 0)return 0;
    if(t >= a + b - 1)return a * b;
    
    long long res = (t * (t + 1)) / 2;
    if(t > a){
        long long c = t - a;
        res -= c * (c + 1) / 2;
    }
    if(t > b){
        long long c = t - b;
        res -= c * (c + 1) / 2;
    }
    
    return res;
}
long long calc(long long r){
    long long ret = 1;
    
    ret += min((long long)x - 1, r) + min((long long)y - 1, r) + min((long long)n - x, r) + 
            min((long long)n - y, r);
    
    ret += solve(x - 1, y - 1, r - 1) + solve(x - 1, n - y, r - 1) +
            solve(n - x, y - 1, r - 1) + solve(n - x, n - y, r - 1);

    return ret;
}
int main(){
    scanf("%d %d %d %d", &n, &x, &y, &c);
    
    long long L = 0, R = 2 * n;
    while(L < R){
        long long r = (L + R) / 2;
        if(calc(r) >= c)R = r;
        else L = r + 1;
    }
    printf("%d\n", (int)L);
    return 0;
}