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

int n, k;
const int maxn = 3005;

ll w[maxn][maxn];
ll f[maxn][maxn];
int v[maxn];
ll ans = 0;

void merge(int d, int l, int r){
    copy(f[d-1] + 1, f[d-1] + k + 1, f[d] + 1);
    for(int i = l;i <= r;i++){
        int V = min(v[i], k);
        for(int j = k;j >= V;j--){
            f[d][j] = max(f[d][j], f[d][j - V] + w[i][V]);
        }
    }
}

void dp(int d, int l, int r){
    if(l == r){
        for(int j = 0;j <= min(v[l], k);j++){
            ans = max(ans, f[d-1][k - j] + w[l][j]);
        }
        return;
    }
    int mid = (l + r) / 2;
    merge(d, mid + 1, r);
    dp(d + 1, l, mid);
    merge(d, l, mid);
    dp(d + 1, mid + 1, r);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        int t;
        cin >> v[i];
        for(int j = 1;j <= v[i];j++){
            cin >> t;
            if(j <= k)
                w[i][j] = w[i][j -1] + t;
        }
        v[i] = min(v[i], k);
    }
    dp(1, 1, n);
    cout << ans << endl;
    return 0;
}