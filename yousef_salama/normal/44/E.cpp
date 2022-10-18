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
#include <string.h>
using namespace std;
int N, k, a, b, dp[205][205], path[205][205];
char s[205];
void PrintPath(int len, int rem){
    if(len == 0 && rem == 0)return;
    PrintPath(len - path[len][rem], rem - 1);
    for(int i = len - path[len][rem], cnt = 0; cnt < path[len][rem]; i++, cnt++)
        printf("%c", s[i]);
    printf("\n");
    return;
}
int main(){
    scanf("%d %d %d", &k, &a, &b);
    scanf("%s", &s);
    N = strlen(s);
    dp[0][0] = 1;
    for(int len = 1; len <= N; len++)
    for(int rem = 0; rem <= k; rem++){
        if(a <= len && len <= b && rem == 1){
            dp[len][rem] = 1;
            path[len][rem] = len;
            continue;
        }
        for(int cut = a; cut <= b && len >= cut; cut++)
            if(rem > 0 && dp[len - cut][rem - 1]){
                dp[len][rem] = 1;
                path[len][rem] = cut;
                break;
            }
    }
    if(!dp[N][k])printf("No solution\n");
    else PrintPath(N, k);
    return 0;
}