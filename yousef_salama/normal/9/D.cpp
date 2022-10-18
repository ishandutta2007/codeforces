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
#define MOD 1000000007
using namespace std;
int N, H;
long long dp[40][40];
int main(){
    scanf("%d %d", &N, &H);
    dp[0][0] = 1;
    for(int i = 0; i <= H; i++)
    for(int z = 1; z <= N; z++)
        for(int cur = 0; cur < z; cur++)
            dp[i][z] += dp[max(i - 1, 0)][cur] * dp[0][z - cur - 1] +
                    dp[0][cur] * dp[max(i - 1, 0)][z - cur - 1] -
                    dp[max(i - 1, 0)][cur] * dp[max(i - 1, 0)][z - cur - 1];
    cout << dp[H][N] << endl;
    return 0;
}