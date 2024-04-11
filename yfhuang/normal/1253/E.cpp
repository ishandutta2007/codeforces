#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
const int maxn = 105;
int le[maxn], ri[maxn];
const int maxm = 1e5 + 5;
int dp[maxm];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int mid, r;
        scanf("%d%d", &mid, &r);
        le[i] = mid - r;
        ri[i] = mid + r;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i <= m;i++){
        dp[i] = i;
        for(int j = 1;j <= n;j++){
            if(le[j] <= i and i <= ri[j]){
                dp[i] = min(dp[i], dp[i - 1]);
            }
            if(ri[j] < i){
                int u = i - ri[j];
                int left = max(1, le[j] - u);
                dp[i] = min(dp[i], dp[left - 1] + u);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}