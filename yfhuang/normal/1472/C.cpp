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

int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<ll> dp(n, 0);
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        ll ans = 0;
        for(int i = n - 1;i >= 0;i--){
            if(i + a[i] >= n){
                dp[i] = a[i];
            }else{
                dp[i] = dp[i + a[i]] + a[i];
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}