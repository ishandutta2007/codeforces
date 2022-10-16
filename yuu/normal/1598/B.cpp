#include <bits/stdc++.h>
using namespace std;
int n;
int b[1000][5];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++) cin >> b[i][j];
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            int cnt_i = 0, cnt_j = 0;
            for (int k = 0; k < n; k++) {
                if (b[k][i] == 0) {
                    if (b[k][j] == 0) goto next_pair;
                    cnt_j++;
                    if (cnt_j * 2 > n) goto next_pair;
                } else {
                    if (b[k][j] == 0) {
                        cnt_i++;
                        if (cnt_i * 2 > n) goto next_pair;
                    }
                }
            }
            cout << "YES\n";
            return;
        next_pair:;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}