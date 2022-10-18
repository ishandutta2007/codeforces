#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int dp[2][MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;

    vector <int> p(m + 1);
    p[0] = -1;
    for(int i = 1; i <= m; i++){
        int j = p[i - 1];
        while(true){
            if(j == -1){
                p[i] = 0;
                break;
            }
            if(b[j] == b[i - 1]){
                p[i] = j + 1;
                break;
            }
            j = p[j];
        }
    }

    for(int j = 0; j < m; j++)
    for(int k = 0; k <= n - m + 1; k++){
        if(j == 0 && k == 0)dp[0][j][k] = 0;
        else dp[0][j][k] = 1 << 20;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
        for(int k = 0; k <= n - m + 1; k++){
            dp[(i & 1) ^ 1][j][k] = 1 << 20;
        }

        for(int j = 0; j < m; j++){
            int y = j, j0, j1;
            while(true){
                if(y == -1){
                    j0 = 0;
                    break;
                }
                if(b[y] == a[i]){
                    j0 = y + 1;
                    break;
                }
                y = p[y];
            }
            y = j;
            while(true){
                if(y == -1){
                    j1 = 0;
                    break;
                }
                if(b[y] != a[i]){
                    j1 = y + 1;
                    break;
                }
                y = p[y];
            }

            for(int k = 0; k <= n - m + 1; k++){
                if(j0 == m){
                    dp[(i & 1) ^ 1][p[m]][k + 1] = min(dp[(i & 1) ^ 1][p[m]][k + 1], dp[i & 1][j][k]);
                }else{
                    dp[(i & 1) ^ 1][j0][k] = min(dp[(i & 1) ^ 1][j0][k], dp[i & 1][j][k]);    
                }
                
                if(j1 == m){
                    dp[(i & 1) ^ 1][p[m]][k + 1] = min(dp[(i & 1) ^ 1][p[m]][k + 1], dp[i & 1][j][k] + 1);
                }else{
                    dp[(i & 1) ^ 1][j1][k] = min(dp[(i & 1) ^ 1][j1][k], dp[i & 1][j][k] + 1);    
                }
            }
        }
    }

    for(int k = 0; k <= n - m + 1; k++){
        if(k > 0)cout << " ";

        int mn = 1 << 20;
        for(int j = 0; j < m; j++)
            mn = min(mn, dp[n & 1][j][k]);

        if(mn == (1 << 20))cout << "-1";
        else cout << mn;
    }
    cout << '\n';

    return 0;
}