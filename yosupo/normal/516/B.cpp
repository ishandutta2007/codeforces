//#define NDEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MN = 2020;
int d4[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
int n, m;
int g[MN][MN];
int num[MN][MN];

bool bc(int x, int y) {
    return (0 <= x && x < m && 0 <= y && y < n);
}

void draw(int x, int y, int xx, int yy) {
    if (x == xx) {
        if (y > yy) swap(y, yy);
        g[y][x] = 4;
        g[yy][x] = 5;
    } else if (y == yy) {
        if (x > xx) swap(x, xx);
        g[y][x] = 2;
        g[y][xx] = 3;
    } else {
        assert(false);
    }
}
bool solve() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (int i = 0; i < 4; i++) {
                if (g[y][x]) continue;
                int yy = y+d4[i][1], xx = x+d4[i][0];
                if (!bc(xx, yy)) continue;
                if (!g[yy][xx]) num[yy][xx]++;
            }
        }
    }
    queue<P> q;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (g[y][x]) continue;
            if (!num[y][x]) return false;
            if (num[y][x] == 1) {
                q.push(P(x, y));
            }
        }
    }
    while (!q.empty()) {
        int x, y, xx = -1, yy;
        tie(x, y) = q.front(); q.pop();
//        printf("%d %d\n", x, y);
        if (g[y][x]) continue;
        for (int i = 0; i < 4; i++) {
            xx = x+d4[i][0]; yy = y+d4[i][1];
            if (g[yy][xx]) continue;
            if (!bc(xx, yy)) continue;
            draw(x, y, xx, yy);
            break;
        }
        if (xx == -1) continue;
        int x2, y2;
        for (int i = 0; i < 4; i++) {
            x2 = x+d4[i][0]; y2 = y+d4[i][1];
            if (g[y2][x2]) continue;
            if (!bc(x2, y2)) continue;
            num[y2][x2]--;
        }
        for (int i = 0; i < 4; i++) {
            x2 = xx+d4[i][0]; y2 = yy+d4[i][1];
            if (g[y2][x2]) continue;
            if (!bc(x2, y2)) continue;
            num[y2][x2]--;
        }
        for (int i = 0; i < 4; i++) {
            x2 = x+d4[i][0]; y2 = y+d4[i][1];
            if (g[y2][x2]) continue;
            if (!bc(x2, y2)) continue;
            if (num[y2][x2] == 1) q.push(P(x2, y2));
        }
        for (int i = 0; i < 4; i++) {
            x2 = xx+d4[i][0]; y2 = yy+d4[i][1];
            if (g[y2][x2]) continue;
            if (!bc(x2, y2)) continue;
            if (num[y2][x2] == 1) q.push(P(x2, y2));
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (!g[y][x]) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = ((s[j] == '*') ? 1 : 0);
        }
    }
    string mp = " *<>^v";
    if (solve()) {
        for (int i = 0; i < n; i++) {
            string rs;
            for (int j = 0; j < m; j++) {
                rs += mp[g[i][j]];
            }
            cout << rs << endl;
        }
    } else {
        cout << "Not unique" << endl;
    }
    return 0;
}