#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int n;

const int maxn = 5e3 + 5;

int dp[maxn][maxn];
int a[maxn];
int sum[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a[0] = a[n + 1] = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] > 0){
            sum[i] = sum[i - 1] + 1;
        }else{
            sum[i] = sum[i - 1];
        }
    } 
    memset(dp, 0x3f, sizeof(dp));
    for(int l = 1;l <= n+1;l++){
        for(int r = l-1;r <= n;r++){
            dp[l][r] = sum[r] - sum[l-1];
        }
    }
    for(int r = 1;r <= n;r++){
        int miid = r;
        for(int l = r;l >= 1;l--){
            if(a[l] < a[miid]){
                miid = l;
            } 
            int delta1 = max(0, a[miid] - a[l-1]);
            int delta2 = max(0, a[miid] - a[r+1]);
            int delta = min(delta1, delta2);
            //if(l == 3 and r == 4){
            //    cout << "!!! " << delta << endl;
            //    cout << dp[l][miid-1] << " " << dp[miid+1][r] << endl;
            //}
            dp[l][r] = min(dp[l][r], dp[l][miid-1] + dp[miid+1][r] + delta); 
        }
    }
    //for(int l = 1;l <= n;l++){
    //    for(int r = l;r <= n;r++){
    //        cout << l << " " << r << " " << dp[l][r] << endl;
    //    }
    //}
    cout << dp[1][n] << endl;
    return 0;
}