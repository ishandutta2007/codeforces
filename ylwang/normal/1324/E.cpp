#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10;

int n , m , L , R , a[N] , dp[N][N];

int Inc(int x){
    return (x + m) % m;
}

int check(int x){
    return L <= x && x <= R;
}

int main(){
    memset(dp , -63 , sizeof(dp)) , dp[0][0] = 0;
    scanf("%d %d %d %d" , &n , &m , &L , &R);
    for(int i = 1; i <= n; i++) scanf("%d" , &a[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++){
            dp[i][j] = max(dp[i - 1][Inc(j - a[i])] , dp[i - 1][Inc(j - a[i] + 1)]) + check(j); 
        }
    int Max = 0;
    for(int i = 0; i < m; i++) Max = max(Max , dp[n][i]);
    printf("%d" , Max);
    return 0;
}