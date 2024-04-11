#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 5005;

int dp[maxn][maxn][2];
vector<int> b;
int a[maxn];
int n;

void upd(int &a, int b){
    if(a > b)
        a = b;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    } 
    for(int i = 1, j = 1;i <= n;i = j + 1, j = i){
        while(j + 1 <= n && a[j + 1] == a[i])
            j++;
        b.push_back(a[j]);
    }
    n = b.size();
    for(int i = 0;i < n;i++){
        dp[i][i][0] = dp[i][i][1] = 0;
        for(int j = 0;j < n;j++){
            if(i != j){
                dp[i][j][0] = dp[i][j][1] = 1e9;
            }
        }
    }
    for(int len = 1;len <= n;len++){
        for(int i = 0;i + len - 1 < n;i++){
            int r = i + len - 1;
            if(i > 0){
                upd(dp[i - 1][r][0], dp[i][r][0] + (b[i - 1] != b[i])); 
                upd(dp[i - 1][r][0], dp[i][r][1] + (b[i - 1] != b[r]));
            }
            if(r + 1 < n){
                upd(dp[i][r + 1][1], dp[i][r][0] + (b[i] != b[r + 1]));
                upd(dp[i][r + 1][1], dp[i][r][1] + (b[r + 1] != b[r]));
            }
        }
    }
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;
    return 0;
}