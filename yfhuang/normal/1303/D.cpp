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

int t;

typedef long long LL;

LL n;
int m;
const int maxn = 1e5 + 5;
int a[maxn];
int cnt[70];
int dp[70];
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        LL sum = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1;i <= m;i++){
            scanf("%d", &a[i]);
            if(sum < n){
                sum += a[i];
            }
            for(int j = 0;j <= 30;j++){
                if(a[i] & (1 << j)){
                    cnt[j]++;
                    break;
                }
            }
        }
        if(sum < n){
            cout << -1 << endl;
        }else{
            int ans = 0;
            for(int i = 0;i < 60;i++){
                if(n & (1LL << i)){
                    for(int k = i;k < 70;k++){
                        if(cnt[k] > 0){
                            ans += k - i;
                            i = max(i, k - 1);
                            cnt[k]--;
                            break;
                        }
                    }     
                }
                cnt[i + 1] += cnt[i] / 2;
            }
            cout << ans << endl;
        }
    }
    return 0;
}