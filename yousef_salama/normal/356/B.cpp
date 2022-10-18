//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

const int MAXN = 1000005;

long long n, m;

int C[MAXN][26];

long long lx, ly;
char x[MAXN], y[MAXN];

int main(){
    scanf("%I64d %I64d %s %s", &n, &m, x, y);
    lx = strlen(x), ly = strlen(y);
    
    memset(C, 0, sizeof C);
    
    int g = __gcd(lx, ly);
    long long l = lx * ly / g;
    
    for(int i = 0; i < lx; i++)
        C[i % g][x[i] - 'a']++;
    
    long long res = l;
    for(int i = 0; i < ly; i++)
        res -= C[i % g][y[i] - 'a'];
    res *= n * lx / l;

    printf("%I64d\n", res);
    
    return 0;
}