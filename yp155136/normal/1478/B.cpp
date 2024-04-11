#include <bits/stdc++.h>
using namespace std;

bool is_good(int x, int d) {
    while (x) {
        if (x % 10 == d) return true;
        x /= 10;
    }
    return false;
}

const int N = 106;
const int INF = 0x3f3f3f3f;
int dis[N][N];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int q, d; cin >> q >> d;
        memset(dis, INF, sizeof(dis));
        for (int i = 1; i <= 100; ++i) {
            if (is_good(i, d)) {
                dis[i % d][i % d] = min(dis[i % d][i % d], i);
            }
        }
        for (int k = 0; k < d; ++k) {
            for (int i = 0; i < d; ++i) {
                for (int j = 0; j < d; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        while (q--) {
            int x; cin >> x;
            string ans = "NO";
            for (int i = 0; i < d; ++i) {
                if (dis[i][x % d] <= x) {
                    ans = "YES";
                }
            }
            cout << ans << endl;
        }
    }
}