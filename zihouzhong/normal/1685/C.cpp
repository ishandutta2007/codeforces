#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, sum[maxn];
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> s, n *= 2;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (s[i] == '(' ? 1 : -1);
        }
        if (!*min_element(sum, sum + n + 1)) {
            cout << "0\n"; continue;
        }
        int l = 0, r = n;
        while (sum[l + 1] >= 0) l++;
        while (sum[r - 1] >= 0) r--;
        l = max_element(sum, sum + l + 1) - sum;
        r = max_element(sum + r, sum + n + 1) - sum;
        auto t = s;
        reverse(t.begin() + l, t.begin() + r);
        int cur = 0;
        bool flag = 1;
        for (char c : t) {
            cur += c == '(' ? 1 : -1;
            flag &= cur >= 0;
        }
        if (flag) {
            cout << "1\n" << l + 1 << " " << r << "\n";
        } else {
            int p = max_element(sum, sum + n + 1) - sum;
            cout << "2\n" << 1 << " " << p << "\n";
            cout << p + 1 << " " << n << "\n";
        }
    }
    return 0;
}