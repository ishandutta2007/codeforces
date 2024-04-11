#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> Q;

int main(int argc, char *argv[]) {
    int r, c;
    char d[1001][1001];
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> d[i];
    }
    P s, g;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (d[i][j] == 'S') {
                s = P(i, j);
            } else if (d[i][j] == 'E') {
                g = P(i, j);
            } else if (d[i][j] != 'T') {
                d[i][j] -= '0';
            }
        }
    }
    const int data[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<Q> que;
    bool used[1001][1001] = {};
    que.push(Q(s, 0));
    used[s.first][s.second] = true;
    int result = 0;
    while (!que.empty()) {
        Q p = que.front(); que.pop();
        for (int i = 0; i < 4; i++) {
            int x = p.first.first, y = p.first.second;
            x += data[i][0];
            y += data[i][1];
            if (0 <= x && x < r && 0 <= y && y < c && d[x][y] != 'T' && !used[x][y]) {
                used[x][y] = true;
                que.push(Q(P(x, y), p.second+1));
                if (x == g.first && y == g.second) {
                    result = p.second+1;
                }
            }
        }
    }
    que.push(Q(g, result));
    fill(used[0], used[0]+1001*1001, false);
    used[g.first][g.second] = true;
    result = 0;
    while (!que.empty()) {
        Q p = que.front(); que.pop();
        if (p.second == 0) continue;
        for (int i = 0; i < 4; i++) {
            int x = p.first.first, y = p.first.second;
            x += data[i][0];
            y += data[i][1];
            if (0 <= x && x < r && 0 <= y && y < c && d[x][y] != 'T' && !used[x][y]) {
                used[x][y] = true;
                que.push(Q(P(x, y), p.second-1));
                if (d[x][y] < 10) {
                    result += d[x][y];
                }
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
// CUT end