#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n;
const int maxn = 1e6 + 5;

typedef pair<int, int> pii;

const int maxm = 21;
int a[maxn];
pii dp[(1 << maxm) + 5];

void add(int num, int pos){
    if(dp[num].first == -1){
        dp[num].first = pos;
    }else{
        if(pos > dp[num].first){
            dp[num].second = dp[num].first;
            dp[num].first = pos;
        }else if(pos == dp[num].first){
            return;
        }else if(pos > dp[num].second and pos < dp[num].first){
            dp[num].second = pos;
        }
    }
}

void merge(int num1, int num2){
    if(dp[num1].first != -1){
        add(num2, dp[num1].first);
    }
    if(dp[num1].second != -1){
        add(num2, dp[num1].second);
    }
}


void solve(){
    cin >> n;
    for(int i = 0;i < (1 << maxm);i++){
        dp[i] = {-1, -1};
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        add(a[i], i);
    }
    for(int i = 0;i < maxm;i++){
        for(int j = 0;j < (1 << maxm);j++){
            if(j & (1 << i)){
                merge(j, j ^ (1 << i));
            }
        }
    }
    int mask = (1 << maxm) - 1;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int w = mask ^ a[i];
        int pre = 0;
        for(int bit = maxm - 1;bit >= 0;bit--){
            if(w & (1 << bit)){
                int now = pre | (1 << bit); 
                if(dp[now].second != -1 and dp[now].second > i){
                    pre = pre | (1 << bit);
                }
                if(dp[pre].second == -1){
                    break;
                }
            }
        }
        //cout << (pre | a[i]) << endl;
        if(dp[pre].second != -1 and dp[pre].first != -1 and dp[pre].second > i) 
            ans = max(ans, pre | a[i]);
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}