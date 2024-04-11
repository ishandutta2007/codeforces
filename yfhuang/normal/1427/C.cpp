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

int r, n;
const int maxn = 1e5 + 5;
int t[maxn], x[maxn], y[maxn];
int dp[maxn];
int pre[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> r >> n;
    for(int i = 1;i <= n;i++){
        cin >> t[i] >> x[i] >> y[i];
        if(x[i] + y[i] - 2 <= t[i]){
            dp[i] = 1;
        }else{
            dp[i] = 0;
        }
        for(int j = i - 1;j >= 1;j--){
            if(t[i] - t[j] >= 2 * (r - 1)){
                dp[i] = max(dp[i], pre[j] + 1);
                break;
            }else{
                if(t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]) and dp[j] > 0){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        pre[i] = max(pre[i - 1], dp[i]);
    }
    cout << pre[n] << endl;
    return 0;
}