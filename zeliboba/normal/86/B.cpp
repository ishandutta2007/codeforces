#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;

char s[1001][1001];
char cnt[1001][1001];
int n, m;

bool in(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '.') {
        cnt[i][j] = 0;
        for (int l1 = -1; l1 < 2; ++l1) for (int l2 = -1; l2 < 2; ++l2) if (l1 * l2 == 0 && (l1 || l2)) {
            if (in(i + l1, j + l2)) {
                if (s[i + l1][j + l2] == '.')
                    ++cnt[i][j];
            }
        }
        if (cnt[i][j] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
//    cerr << "here\n";
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '.') {
        vii cur(1, pii(i, j));
        s[i][j] = ' ';
        if (j + 1 < m && s[i][j + 1] == '.') {
            cur.push_back(pii(i, j + 1));
            s[i][j + 1] = ' ';
        } else {
            assert(i < n - 1 && s[i + 1][j] == '.');
            cur.push_back(pii(i + 1, j));
            s[i + 1][j] = ' ';
        }
        int it = 0;
        vi forbid(10, 0);
        while (it < cur.size()) {
            int i1 = cur[it].first, j1 = cur[it].second;
            for (int l1 = -1; l1 < 2; ++l1) for (int l2 = -1; l2 < 2; ++l2) if (l1 * l2 == 0 && (l1 || l2)) {
                int i2 = i1 + l1, j2 = j1 + l2;
                if (in(i2, j2)) {
                    if (s[i2][j2] == '.') {
//                        cerr << i2 << " " << j2 << " " << (int)cnt[i2][j2] << endl;
                        if (cnt[i2][j2] == 1) {
                            cur.push_back(pii(i2, j2));
                            s[i2][j2] = ' ';
                        } else cnt[i2][j2]--;
                    } else {
                        if (s[i2][j2] >= '0' && s[i2][j2] <= '9')
                            forbid[s[i2][j2] - '0'] = 1;
                    }
                }
            }
            ++it;
        }
        int col = 0;
        for (it = 0; it < 10; ++it) if (!forbid[it]) {
            col = it;
            break;
        }
        for (it = 0; it < cur.size(); ++it)
            s[cur[it].first][cur[it].second] = col + '0';
    }
    for (int i = 0; i < n; ++i)
        printf("%s\n", s[i]);
    return 0;
}