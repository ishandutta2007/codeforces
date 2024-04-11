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
#define MOD 1000000007
using namespace std;
long long n;
int main(){
    scanf("%I64d", &n);
    if(n == 1)printf("1\n");
    else if(n == 2)printf("2\n");
    else if(n % 2 == 0){
        long long ret = 0;
        for(long long a = max(1LL, n - 100); a <= n; a++)
        for(long long b = max(1LL, n - 100); b <= n; b++)
        for(long long c = max(1LL, n - 100); c <= n; c++){
            long long ans = a * b;
            ans /= __gcd(a, b);
            ans = ans * c / __gcd(ans, c);

            ret = max(ret, ans);
        }
        printf("%I64d\n", ret);
    }else{
        printf("%I64d\n", n * (n - 1) * (n - 2));
    }
    return 0;
}