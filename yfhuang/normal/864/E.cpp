#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

struct item{
    int t,d,p,id;
    bool operator < (const item & rhs) const{
        return d < rhs.d;
    }
    void read(){
        cin >> t >> d >> p;
    }
}a[105];

int dp[105][2005];
int pre[105][2005];
int ret[105],tot;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        a[i].read();
        a[i].id = i;
    }
    sort(a + 1,a + 1 + n);
    memset(dp,0,sizeof(dp));
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 2000;j++){
            dp[i][j] = dp[i - 1][j];
            pre[i][j] = 0;
        }
        for(int j = 0;j + a[i].t < a[i].d;j++){
            if(dp[i - 1][j] + a[i].p > dp[i][j + a[i].t]){
                dp[i][j + a[i].t] = dp[i - 1][j] + a[i].p;
                pre[i][j + a[i].t] = 1;
            }
        }
    }
    int ans = 0;
    int id = -1;
    for(int j = 0;j <= 2000;j++){
        if(dp[n][j] > ans){
            ans = dp[n][j];
            id = j;
        }
    }
    cout << ans << endl;
    int now = id;
    tot = 0;
    for(int i = n;i >= 1;i--){
        if(pre[i][now] == 1){
            now -= a[i].t;
            ret[++tot] = a[i].id;
        }
    }
    cout << tot << endl;
    for(int i = tot;i >= 1;i--){
        cout << ret[i] << " ";
    }
    return 0;
}