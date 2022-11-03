#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int  n,m;

const int maxn = 1e5 + 5;

int w[5][maxn];
int num[5];

pair<long long,pair<int,int>> dp[maxn * 3];

#define mp make_pair

int main(){
    cin >> n >> m;
    memset(num,0,sizeof(num));
    for(int i = 1;i <= n;i++){
        int wei,val;
        scanf("%d%d",&wei,&val);
        w[wei][++num[wei]] = val;
    }
    for(int i = 1;i <= 3;i++)sort(w[i] + 1,w[i] + 1 + num[i]);
    dp[0] = mp(0LL,mp(0,0));
    for(int i = 1;i <= m;i++){
        dp[i] = dp[i - 1];
        if(i > 1 && dp[i - 2].second.second < num[2]){
            int used = dp[i - 2].second.second;
            if(dp[i].first < dp[i - 2].first + w[2][num[2] - used]){
                dp[i] = mp(dp[i - 2].first + w[2][num[2] - used],mp(dp[i - 2].second.first,dp[i - 2].second.second + 1));
            }
        }
        if(dp[i - 1].second.first < num[1]){
            int used = dp[i - 1].second.first;
            if(dp[i].first < dp[i - 1].first + w[1][num[1] - used]){
                dp[i] = mp(dp[i - 1].first + w[1][num[1] - used],mp(dp[i - 1].second.first + 1,dp[i - 1].second.second));
            }
        }
    }
    long long ans = 0;
    long long sum = 0;
    for(int i = 0;i <= num[3] && 3 * i <= m;i++){
        ans = max(ans,sum + dp[m - 3 * i].first);
        sum += w[3][num[3] - i];
    }
    cout << ans << endl;
    return 0;
}