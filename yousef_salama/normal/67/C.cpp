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

const int MAXN = 4005;

int t_insert, t_delete, t_replace, t_exchange;
char A[MAXN], B[MAXN];
int nA, nB;

int nextA[MAXN][26], nextB[MAXN][26];
int dp[MAXN][MAXN];

int solve(int i, int j){
    if(dp[i][j] != -1)return dp[i][j];
    
    if(i == nA && j == nB)return dp[i][j] = 0;
    if(j == nB){
        return dp[i][j] = t_delete + solve(i + 1, j);
    }
    if(i == nA){
        return dp[i][j] = t_insert + solve(i, j + 1);
    }
    
    int res = 1 << 30;
    if(A[i] == B[j])res = min(res, solve(i + 1, j + 1));
    else res = min(res, t_replace + solve(i + 1, j + 1));
    
    res = min(res, t_insert + solve(i, j + 1));
    res = min(res, t_delete + solve(i + 1, j));

    if(i + 1 < nA && j + 1 < nB){
        int ni = nextA[i + 1][B[j] - 'a'];
        int nj = nextB[j + 1][A[i] - 'a'];
        /*
        if(nj < nB)
            res = min(res, solve(i + 2, nj + 1) + t_exchange + 
                + t_replace + t_insert * (nj - j - 1));
        if(ni < nA)
            res = min(res, solve(ni + 1, j + 2) + t_exchange +
                + t_replace + t_delete * (ni - i - 1));
        */
        if(nj < nB && ni < nA)
            res = min(res, solve(ni + 1, nj + 1) + t_exchange + 
                t_insert * (nj - j - 1) + t_delete * (ni - i - 1));
    }
    
    return dp[i][j] = res;
}
    
int main(){
    scanf("%d %d %d %d", &t_insert, &t_delete, &t_replace, &t_exchange);
    scanf("%s %s", A, B);
    nA = strlen(A), nB = strlen(B);
    
    for(char c = 'a'; c <= 'z'; c++){
        nextA[nA][c - 'a'] = nA;
        for(int i = nA - 1; i >= 0; i--){
            if(A[i] == c)nextA[i][c - 'a'] = i;
            else nextA[i][c - 'a'] = nextA[i + 1][c - 'a'];
        }
    }
    for(char c = 'a'; c <= 'z'; c++){
        nextB[nB][c - 'a'] = nB;
        for(int i = nB - 1; i >= 0; i--){
            if(B[i] == c)nextB[i][c - 'a'] = i;
            else nextB[i][c - 'a'] = nextB[i + 1][c - 'a'];
        }
    }
    
    
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, 0));
    
    return 0;
}