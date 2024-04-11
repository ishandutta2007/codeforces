#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef double ld;
int dir4[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
struct Pi {
    int x, y;
    Pi(int xx, int yy) {
        x = xx; y = yy;
    }
};
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s;
    for (int i = 0; i < n; i++) {
        string ss;
        cin >> ss;
        s.push_back(ss);
    }
    queue<Pi> que;
    int r = 0;
    bool used[510][510] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                r++;
                if (que.empty()) {
                    que.push(Pi(i, j));
                    used[i][j] = true;
                }
            }
        }
    }
    vector<Pi> res;
    while (!que.empty()) {
        Pi p = que.front(); que.pop();
        res.push_back(p);
        if (res.size() == r-k) break;
        for (int i = 0; i < 4; i++) {
            int xx = p.x + dir4[i][0], yy = p.y + dir4[i][1];
            if (0 <= xx && xx < n && 0 <= yy && yy < m && !used[xx][yy] && s[xx][yy] == '.') {
                used[xx][yy] = true;
                que.push(Pi(xx, yy));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.')
                s[i][j] = 'X';
        }
    }
    for (Pi p: res) {
        s[p.x][p.y] = '.';
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}