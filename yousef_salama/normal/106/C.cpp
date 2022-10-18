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
#define oo 1 << 25
using namespace std;
struct stuf{
    int a, b, c, d;
    stuf(int i, int j, int k, int l){
        a = i;
        b = j;
        c = k;
        d = l;
    }
};
int N, M, d0, c0;
int a, b, c, d;
int dp[12][1001];
stuf* s[11];
int main(){
    scanf("%d %d %d %d", &N, &M, &c0, &d0);
    for(int i = 1; i <= M; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        s[i] = new stuf(a, b, c, d);
    }
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= N; i++)
        dp[M + 1][i] = 0;
    for(int idx = M; idx > 0; idx--)
    for(int rem = 0; rem <= N; rem++)
        for(int buns = 0; (buns * s[idx]->b) <= s[idx]->a && (buns * s[idx]->c) <= rem; buns++)
            dp[idx][rem] = max(dp[idx][rem], (buns * s[idx]->d) + dp[idx + 1][rem - (buns * s[idx]->c)]);
    for(int rem = 0; rem <= N; rem++)
        for(int buns = 0; (buns * c0) <= rem; buns++)
            dp[0][rem] = max(dp[0][rem], (buns * d0) + dp[1][rem - (buns * c0)]);
    printf("%d\n", dp[0][N]);
    return 0;
}