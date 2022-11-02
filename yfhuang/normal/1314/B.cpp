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

int n, k;

const int maxn = (1 << 20);
int a[maxn];
int vis[maxn];
int dp[maxn][2][2];

void solve(int o, int win1, int lose1, int win2 , int lose2){
    if(dp[o*2][win1][lose1] < 0 || dp[o*2+1][win2][lose2] < 0)
       return;
    int cnt;
    int newwin = max(win1, win2);
    int newlose = max(lose1, lose2);
    int newlose1 = max(newlose, win1 + win2 - newwin); 
    cnt = ((newwin > 0) + (newlose > 0) + (newlose1 > 0));
    dp[o][newwin][newlose1] = max(dp[o][newwin][newlose1], dp[o*2][win1][lose1] + dp[o*2+1][win2][lose2] + cnt);
}


int main(){
    cin >> n >> k;
    for(int i = 1;i <= k;i++){
        int a;
        scanf("%d", &a);a--;
        vis[a] = 1;
    } 
    memset(dp, -1, sizeof(dp));
    int offset = (1 << (n - 1));
    for(int i = 0;i < (1 << (n - 1));i++){
        if(vis[i * 2] + vis[i * 2 + 1] == 0){
            dp[i + offset][0][0] = 0; 
        }
        if(vis[i * 2] + vis[i * 2 + 1] == 1){
            dp[i + offset][0][1] = 1;
            dp[i + offset][1][0] = 1;
        }
        if(vis[i * 2] + vis[i * 2 + 1] == 2){
            dp[i + offset][1][1] = 1;
        }
    }
    for(int i = offset - 1;i > 0;i--){
        for(int win1 = 0;win1 < 2;win1++){
            for(int lose1 = 0;lose1 < 2;lose1++){
                for(int win2 = 0;win2 < 2;win2++){
                    for(int lose2 = 0;lose2 < 2;lose2++){
                        solve(i, win1, lose1, win2, lose2);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int win = 0;win < 2;win++){
        for(int lose = 0;lose < 2;lose++){
            ans = max(ans, dp[1][win][lose] + (win | lose));
        }
    }
    cout << ans << endl;
    return 0;
}