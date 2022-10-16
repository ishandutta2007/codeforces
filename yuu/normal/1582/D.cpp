#include <bits/stdc++.h>
#define pdebug(x) cerr << __LINE__ << ": " << #x << " = " << x << '\n'
using namespace std;

int n;
int a[100001];
int b[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int d = abs(a[1]);
    for (int i = 2; i <= n; i++)
        if (a[i] % d) {
            d = gcd(d, abs(a[i]));
        }
    for (int i = 1; i <= n; i++) a[i] /= d;

    int mi = 1;
    for (int i = 2; i <= n; i++)
        if (abs(a[i]) < abs(a[mi])) mi = i;

    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (i != mi) {
            if (sum + a[i]) {
                if (sum - a[i]) {
                    if (abs(sum - a[i]) < abs(sum + a[i])) {
                        sum -= a[i];
                        b[i] = -1;
                        continue;
                    }
                }
                sum += a[i];
                b[i] = 1;
            } else {
                sum -= a[i];
                b[i] = -1;
            }
        }
    for (int i = 1; i <= n; i++) b[i] *= a[mi];

    b[mi] = -sum;

    for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
    int test = 0;
    for (int i = 1; i <= n; i++) test += a[i] * b[i];
    pdebug(test);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}