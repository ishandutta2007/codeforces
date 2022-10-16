#include <bits/stdc++.h>
using namespace std;
int n;
class Product {
  public:
    int64_t a, b;
} p[200001];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
    }
    sort(p + 1, p + n + 1, [](const Product& A, const Product& B) { return A.b < B.b; });
    int low = 1, high = n;
    int64_t ans = 0;
    int64_t bought = 0;
    while (low <= high) {
        if (p[low].b <= bought) {
            bought += p[low].a;
            ans += p[low].a;
            low++;
        } else {
            int64_t buy = min(p[low].b - bought, p[high].a);
            p[high].a -= buy;
            bought += buy;
            ans += buy * 2;
            if (p[high].a == 0) high--;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}