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
int N;
long long x[100005], y[100005];
int main(){
    scanf("%d", &N);

    long long res = 0, sx = 0, sy = 0, sqx = 0, sqy = 0;
    for(int i = 0; i < N; i++){
        scanf("%I64d %I64d", &x[i], &y[i]);
        
        res += i * x[i] * x[i] - 2 * x[i] * sx + sqx;
        res += i * y[i] * y[i] - 2 * y[i] * sy + sqy;
        
        sx += x[i], sy += y[i];
        sqx += x[i] * x[i], sqy += y[i] * y[i];
    }
    printf("%I64d\n", res);
    return 0;
}