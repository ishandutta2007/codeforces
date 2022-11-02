#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 5003;
const ll INF = 1e18;

int n, m;
ll sum[maxn];
int x[maxn];
pi h[maxn];
ll dp[2][maxn];

void init(int id){
    sum[0] = 0;
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i-1] + abs(x[i] - h[id].fi);
    } 
}

void Dp(int i, int l, int r, int ql, int qr){
    if(r < l)
        return;
    int cur = i & 1;
    int pre = cur ^ 1;
    int mid = (l + r) / 2;
    ll val = dp[pre][mid] - sum[mid]; 
    int mi = max(ql, mid - h[i].se);
    int opt = mid;
    for(int i = mi; i <= min(mid, qr);i++){
        ll tmp = dp[pre][i] - sum[i];
        if(tmp < val){
            val = tmp;
            opt = i;
        } 
    }
    dp[cur][mid] = val + sum[mid];
    Dp(i, l, mid - 1, ql, opt);
    Dp(i, mid + 1, r, opt, qr);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> x[i];
    }
    sort(x + 1, x + 1 + n);
    for(int i = 1;i <= m;i++){
        cin >> h[i].fi >> h[i].se;
    }
    sort(h + 1, h + 1 + m);
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        dp[0][i] = INF;
    }
    for(int i = 1;i <= m;i++){
        int cur = i & 1;
        int pre = cur ^ 1; 
        init(i);
        Dp(i, 0, n, 0, n);
    }
    if(dp[m & 1][n] == INF){
        dp[m & 1][n] = -1;
    }
    cout << dp[m & 1][n] << endl;
    return 0;
}