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

int n, k, q;
const int maxn = 5005;
int dp[maxn][maxn];
int a[maxn];

const int mod = 1e9 + 7;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> q; 
    for(int i = 1;i <= n;i++){
        dp[0][i] = 1; 
    }
    for(int i = 1;i <= k;i++){
        for(int j = 1;j <= n;j++){
            if(j > 1)
                add(dp[i][j], dp[i - 1][j - 1]);
            if(j < n)
                add(dp[i][j], dp[i - 1][j + 1]);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= k;j++){
            cnt[i] = (cnt[i] + 1LL * dp[j][i] * dp[k - j][i]) % mod;
        }
    } 
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        add(sum, 1LL * a[i] * cnt[i] % mod);
    }
    for(int i = 1;i <= q;i++){
        int x, y;
        cin >> x >> y;
        sum = (sum - 1LL * a[x] * cnt[x] % mod + mod) % mod;
        a[x] = y;
        sum = (sum + 1LL * a[x] * cnt[x] % mod) % mod;
        cout << sum << endl;
    }
    return 0;
}