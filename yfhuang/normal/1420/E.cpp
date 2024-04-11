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

int n;
const int maxn = 100 + 5;
int a[maxn];
int b[maxn];
int m;
int dp[2][maxn * 2][maxn * maxn];
int pre[maxn];
int ans[maxn * maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int pre1 = 0;
    m = 0;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 1){
            b[++m] = i - pre1 - 1;
            pre1 = i;
        }else{
            sum++;
        }
    }
    b[++m] = n - pre1;
    pre[0] = 0;
    for(int i = 1;i <= m;i++){
        pre[i] = pre[i - 1] + b[i];
    }
    int OP = (n + 1) / 2 * (n + 1) / 2;
    memset(dp, -1, sizeof(dp));
    dp[0][sum][0] = 0;
    for(int i = 1;i <= m;i++){
        int nxt = i & 1;
        int cur = nxt ^ 1;
        memset(dp[nxt], -1, sizeof(dp[nxt]));
        for(int j = 0;j <= sum * 2;j++){
            for(int k = 0;k <= OP;k++){
                if(dp[cur][j][k] == -1){
                    continue;
                }
                int used = pre[i-1] + (sum - j);
                int left = sum - used;
                for(int l = 0;l <= left;l++){
                    int borrow = j - (l - b[i]);
                    if(borrow < 0 or borrow > sum * 2)
                        continue;
                    int op = k + abs(sum - borrow);
                    if(op > OP)
                        continue;
                    if(dp[nxt][borrow][op] == -1){
                        dp[nxt][borrow][op] = dp[cur][j][k] + l * l; 
                    }else{
                        dp[nxt][borrow][op] = min(dp[nxt][borrow][op], dp[cur][j][k] + l * l);
                    }
                }
            }
        }
    }
    for(int i = 0;i <= n * (n - 1) / 2;i++){
        ans[i] = 1e9;
        if(i <= OP and dp[m & 1][sum][i] != -1)
            ans[i] = dp[m & 1][sum][i];
        if(i > 0)
            ans[i] = min(ans[i - 1], ans[i]);
        cout << (sum * sum - ans[i]) / 2 << " ";
    }
    return 0;
}