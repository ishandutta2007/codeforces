#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m, a[MAXN][MAXN], dp[4][MAXN][MAXN], tdp[4][MAXN][MAXN];
void add(int d, int fn, int fm){
    for(int i = n - 1; i >= 0; i--)
    for(int j = m - 1; j >= 0; j--){
        if(i == n - 1 && j == m - 1)tdp[d][i][j] = a[fn ? n - i - 1 : i][fm ? m - j - 1 : j];
        else{
            tdp[d][i][j] = 0;

            int x = a[fn ? n - i - 1 : i][fm ? m - j - 1 : j];
            if(i + 1 < n)tdp[d][i][j] = max(tdp[d][i][j], tdp[d][i + 1][j] + x);
            if(j + 1 < m)tdp[d][i][j] = max(tdp[d][i][j], tdp[d][i][j + 1] + x);
        }
        dp[d][fn ? n - i - 1 : i][fm ? m - j - 1 : j] = tdp[d][i][j];
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);

    add(0, 0, 0);
    add(1, 0, 1);
    add(2, 1, 0);
    add(3, 1, 1);

    int r = 0;
    for(int i = 1; i < n - 1; i++)
    for(int j = 1; j < m - 1; j++){
    	r = max(r, dp[0][i][j + 1] + dp[1][i + 1][j] + dp[2][i - 1][j] + dp[3][i][j - 1]);
    	r = max(r, dp[0][i + 1][j] + dp[1][i][j - 1] + dp[2][i][j + 1] + dp[3][i - 1][j]);
    }
    printf("%d\n", r);


    return 0;
}