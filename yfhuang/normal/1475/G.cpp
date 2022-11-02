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

int T;
int n;
const int maxn = 2e5 + 5;
int a[maxn];

vector<int> divisors[maxn];

void init(){
    for(int i = 1;i < maxn;i++){
        for(int j = i;j < maxn;j += i){
            divisors[j].push_back(i);
        }
    }
}

int dp[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    init();
    while(T--){
        cin >> n;
        int ans = n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        memset(dp, 0, sizeof(dp));
        for(int i = 1;i <= n;i++){
            dp[a[i]] = max(dp[a[i]], dp[a[i]] + 1);
            for(auto v : divisors[a[i]]){
                if(v == a[i])
                    continue;
                dp[a[i]] = max(dp[v] + 1, dp[a[i]]);
            }
            ans = min(ans, n - dp[a[i]]);
        }
        cout << ans << endl;
    }
    return 0;
}