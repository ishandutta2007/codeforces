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

int n, r;
const int maxn = 105;

int a[maxn], b[maxn];

int dp[maxn][60005];
typedef pair<int, int> pii;

int main(){
    cin >> n >> r;
    vector<pii> pos, neg;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &a[i], &b[i]);
        if(b[i] >= 0){
            pos.push_back(make_pair(a[i], b[i]));
        }else{
            a[i] = max(a[i], -b[i]);
            neg.push_back(make_pair(-a[i] - b[i], i));
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int ans = 0;
    for(auto p : pos){
        int rating = p.first;
        int gain = p.second;
        if(r >= rating){
            r += gain;
            ans++;
        }
    }
    memset(dp, -1, sizeof(dp));
    //cout << r << endl;
    dp[0][r] = 0;
    //cout << neg.size() << endl;
    for(int i = 0;i < neg.size();i++){
        for(int j = 0;j <= 60000;j++){
            if(dp[i][j] == -1)
                continue;
            int id = neg[i].second;
            if(j >= a[id]){
                dp[i + 1][j + b[id]] = max(dp[i + 1][j + b[id]], dp[i][j] + 1);  
            } 
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    int ans1 = 0;
    for(int i = 0;i <= neg.size();i++){
        for(int j = 0;j <= 60000;j++){
            ans1 = max(ans1, dp[i][j]);
        }
    }
    cout << ans + ans1 << endl;
    return 0;
}