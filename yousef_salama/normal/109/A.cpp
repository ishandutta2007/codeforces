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
#define eps 1e-9
#define For(it, c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
using namespace std;
int dp[(int)1e6 + 5], N;
void BuildPath(int rem){
    if(rem <= 0)printf("\n");
    else{
        if(dp[rem] == dp[rem - 4] + 1){
            printf("4");
            BuildPath(rem - 4);
        }else{
            printf("7");
            BuildPath(rem - 7);
        }
    }
}
int main(){
    scanf("%d", &N);
    dp[0] = 0;
    for(int rem = 1; rem <= N; rem++)
        dp[rem] = min((rem - 4 >= 0?dp[rem - 4] + 1:1 << 30),
                (rem - 7 >= 0?dp[rem - 7] + 1:1 << 30));
    if(dp[N] >= 1 << 30)printf("-1\n");
    else BuildPath(N);
    return 0;
}