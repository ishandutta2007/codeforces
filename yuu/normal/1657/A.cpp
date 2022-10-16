#include <bits/stdc++.h>
using namespace std;
int ans[51][51];
void prepare() {
    for (int i = 0; i <= 50; i++)
        for (int j = 0; j <= 50; j++) {
            int val = i * i + j * j;
            int r = sqrt(val);
            while (r * r > val) r--;
            while (r * r < val) r++;
            if (r * r == val)
                ans[i][j] = 1;
            else
                ans[i][j] = 2;
        }
    ans[0][0] = 0;
}

void solve() {
    int x, y;
    cin >> x >> y;
    cout << ans[x][y] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    prepare();
    cin >> t;
    while (t--) solve();
}