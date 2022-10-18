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
#define MOD 1000000007
using namespace std;
char s[700];
int N, m[700];
int dp[705][705][3][3];
stack <int> st;
int dfs(int l, int r, int cl, int cr){
    if(dp[l][r][cl][cr] != -1)return dp[l][r][cl][cr];
    if(l > r)return cl == 0 && cr == 0;
    int k = m[l];
    long long res = 0;
    if(k == r){
        if(!((cl == 0) ^ (cr == 0)))return 0;
        for(int i = 0; i <= 2; i++)
        for(int j = 0; j <= 2; j++)
            if((cl != i || cl == 0) && (cr != j || cr == 0))
                res = (res + dfs(l + 1, r - 1, i, j)) % MOD;
    }else{
        for(int i = 0; i <= 2; i++)
        for(int j = 0; j <= 2; j++)
            if(i == 0 || j == 0 || i != j)
                res = (res + (long long)dfs(l, k, cl, i) * dfs(k + 1, r, j, cr)) % MOD;
    }
    return dp[l][r][cl][cr] = res;
}
int main(){
    scanf("%s", &s);
    N = strlen(s);
    for(int i = 0; i < N; i++){
        if(s[i] == '(')
            st.push(i);
        else{
            int k = st.top();
            st.pop();
            m[k] = i;
            m[i] = k;
        }
    }
    memset(dp, -1, sizeof dp);
    long long res = 0;
    for(int i = 0; i <= 2; i++)
    for(int j = 0; j <= 2; j++)
        res = (res + dfs(0, N - 1, i, j)) % MOD;
    printf("%d\n", (int)res);
    return 0;
}