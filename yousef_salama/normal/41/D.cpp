#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
bool dp[105][105][1005];
int p[105][105], n, m, k;
stack <string> path;
int path_rec(int i, int j, int l){
    if(i == n - 1)return j;
    int nk = l - p[i][j];
    if(j + 1 < m && dp[i + 1][j + 1][nk]){
        path.push("L");
        return path_rec(i + 1, j + 1, nk);
    }
    else{
        path.push("R");
        return path_rec(i + 1, j - 1, nk);
    }
}
int main(){
//    freopen("a.in", "r", stdin);
    cin >> n >> m >> k;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++)
            p[i][j] = s[j] - '0';
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int l = 0; l < 1005; l++)
                dp[i][j][l] = 0;
    for(int i = 0; i < m; i++)
        dp[n - 1][i][p[n - 1][i]] = 1;
    for(int j = 0; j < m; j++){
        if(j - 1 >= 0)dp[n - 2][j - 1][p[n - 1][j] + p[n - 2][j - 1]] = 1;
        if(j + 1 < m)dp[n - 2][j + 1][p[n - 1][j] + p[n - 2][j + 1]] = 1;
    }
    for(int i = n - 2; i > 0; i--)
        for(int j = 0; j < m; j++)
            for(int l = 0; l < 1005; l++)if(dp[i][j][l]){
                if(j - 1 >= 0)dp[i - 1][j - 1][l + p[i - 1][j - 1]] = 1;
                if(j + 1 < m)dp[i - 1][j + 1][l + p[i - 1][j + 1]] = 1;
            }
    int index = -1, ans = -1;
    for(int j = 0; j < m; j++)
        for(int l = 0; l < 1005; l++)if(dp[0][j][l] && (l % (k + 1)) == 0){
            index = j;
            ans = l;
        }
    for(int j = 0; j < m; j++)
        for(int l = 0; l < 1005; l++)if(dp[0][j][l] && (l % (k + 1)) == 0 && ans < l){
            index = j;
            ans = l;
        }
    if(ans == -1)cout << -1 << endl;
    else{
        cout << ans << endl;
        cout << path_rec(0, index, ans) + 1 << endl;
        while(!path.empty()){
            cout << path.top();
            path.pop();
        }
        cout << endl;
    }
    return 0;
}