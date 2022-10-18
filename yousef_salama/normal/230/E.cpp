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
#include <cstring>
#include <sstream>
using namespace std;
long long n, m, c[1000005];
int a, b;
int main(){
    scanf("%I64d %I64d", &n, &m);
    for(int itr = 0; itr < m; itr++){
        scanf("%d %d", &a, &b);
        c[a - 1]++;
        c[b - 1]++;
    }
    
    long long ans = 0;
    
    for(int i = 0; i < n; i++){
        ans += c[i] * (n - c[i] - 1);
    }
    ans /= 2;
    long long total = n * (n - 1) * (n - 2) / 6;
    
    printf("%I64d\n", total - ans);
    return 0;
}