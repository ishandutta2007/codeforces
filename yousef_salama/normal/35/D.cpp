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
int N, X, c[105], dp[105][10005];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)
        scanf("%d", &c[i]);
    for(int i = N - 1; i >= 0; i--)
    for(int rem = 0; rem <= X; rem++)
        dp[i][rem] = max(dp[i + 1][rem], (rem - (N - i) * c[i] >= 0?
            1 + dp[i + 1][rem - (N - i) * c[i]]:0));
    printf("%d\n", dp[0][X]);
    return 0;
}