#include <bits/stdc++.h>
using namespace std;

int n;
typedef long long ll;
const int maxn = 1e5 + 5;
ll v[maxn], t[maxn];
ll pre[maxn];

int cnt[maxn];
ll sum[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> v[i];
    }
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> t[i];
        pre[i] = pre[i - 1] + t[i];
    }
    for(int i = 1;i <= n;i++){
        ll val = pre[i - 1] + v[i];
        int id = lower_bound(pre + 1, pre + 1 + n, val) - pre;
        sum[id] += val - pre[id - 1];
        cnt[i]++;
        cnt[id]--;
    }
    for(int i = 1;i <= n;i++){
        cnt[i] += cnt[i - 1];
        cout << cnt[i] * t[i] + sum[i] << " ";
    }
    return 0;
}