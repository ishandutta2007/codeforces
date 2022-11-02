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

int n;
const int maxn = 5005;
int a[maxn];
int l[maxn], r[maxn];

const int mod = 998244353;
int dp[maxn][maxn];
int pre[maxn];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    } 
    sort(a + 1, a + 1 + n);
    int j = 0;
    for(int i = 1;i <= n;i++){
        while(j < n and a[j + 1] * 2 <= a[i]){
            j++;
        }
        l[i] = j;
    }
    j = n + 1;
    for(int i = n;i >=1 ;i--){
        while(j > 1 and a[j - 1] >= 2 * a[i]){
            j--;
        }
        r[i] = j;
    }
    for(int i = 1;i <= n;i++){
        dp[1][i] = 1;
    }
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= n;j++){
            add(dp[i][j], 1LL * dp[i - 1][j] * max(0, l[j] - i + 2) % mod);
        } 
        memset(pre, 0, sizeof(pre));
        for(int j = 1;j <= n;j++){
            add(pre[r[j]], dp[i - 1][j]);
        }
        for(int j = 1;j <= n;j++){
            add(pre[j], pre[j - 1]);
        }
        for(int j = 1;j <= n;j++){
            add(dp[i][j], pre[j]);
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}