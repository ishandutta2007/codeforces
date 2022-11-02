#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;
const int maxn = 2e5 + 5;
ll dp[maxn][3][2][2];
int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        for(int j = 0;j < 3;j++){
            for(int k = 0;k < 2;k++){
                for(int l = 0;l < 2;l++){
                    dp[i][j][k][l] = -1e18;
                }
            }
        }
    } 
    if(n == 1){
        cout << a[1] << endl;
        return 0;
    }
    dp[1][1][1][0] = a[1];
    dp[1][2][0][0] = -a[1];
    for(int i = 2;i <= n;i++){
        for(int j = 0;j < 3;j++){
            for(int k = 0;k < 2;k++){
                for(int l = 0;l < 2;l++){
                    dp[i][(j + 1) % 3][1][(k == 1) | l] = max(dp[i][(j + 1) % 3][1][(k == 1) | l], dp[i - 1][j][k][l] + a[i]);
                    dp[i][(j + 2) % 3][0][(k == 0) | l] = max(dp[i][(j + 2) % 3][0][(k == 0) | l], dp[i - 1][j][k][l] - a[i]);
                }
            }
        }
    }
    ll ans = -1e18;
    ans = max(dp[n][1][0][1], dp[n][1][1][1]);
    cout << ans << endl;
    return 0;
}