#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, k, a[N], pre[N], suf[N], ans = LLONG_MAX, cnt[N];
signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1); //
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for(int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == a[i - 1]) cnt[i] = cnt[i - 1] + 1;
        else cnt[i] = 1;
        if(cnt[i] >= k) return puts("0") && 0;
    } 
    for(int i = 1; i <= n; i++)
    {
        if(i >= k) ans = min(ans, i * a[i] - pre[i] - (i - k));
        if(n - i + 1 >= k) ans = min(ans, suf[i] - (n - i + 1) * a[i] - (n - i + 1 - k));
        ans = min(ans, i * a[i] - pre[i] + suf[i] - (n - i + 1) * a[i] - (n - k));
    } 
    cout << ans << endl;
    return 0;
}