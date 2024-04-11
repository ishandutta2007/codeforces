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
int N, a[1001], dp[1001][1001], path[1001][1001];
int dfs(int i, int j){
    if(i >= N)return 0;
    if(j >= N)return a[i];
    if(j + 1 >= N)return max(a[i], a[j]);
    
    if(dp[i][j] != -1)return dp[i][j];
    int w1 = max(a[i], a[j]) + dfs(j + 1, j + 2);
    int w2 = max(a[i], a[j + 1]) + dfs(j, j + 2);
    int w3 = max(a[j], a[j + 1]) + dfs(i, j + 2);
    int Min = min(w1, min(w2, w3));

    if(Min == w1)path[i][j] = 0;
    if(Min == w2)path[i][j] = 1;
    if(Min == w3)path[i][j] = 2;

    return dp[i][j] = Min;
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
    int ans = dfs(0, 1);
    cout << ans << endl;
    int i = 0, j = 1;
    while(i < N || j < N){
        if(j >= N){
            cout << i + 1 << endl;
            break;
        }
        int ni, nj;
        if(path[i][j] == 0){
            printf("%d %d\n", i + 1, j + 1);
            ni = j + 1;
            nj = j + 2;
        }else if(path[i][j] == 1){
            printf("%d %d\n", i + 1, j + 2);
            ni = j;
            nj = j + 2;
        }else{
            printf("%d %d\n", j + 1, j + 2);
            ni = i;
            nj = j + 2;
        }
        i = ni;
        j = nj;
    }
    return 0;
}