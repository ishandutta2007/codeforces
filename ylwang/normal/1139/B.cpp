#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 6;
int n, a[N], x = 1e9 + 1;
ll ans;
 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i; i--) {
        x = min(a[i], x - 1);
        if (x > 0) ans += x;
    }
    cout << ans << endl;
    return 0;
}