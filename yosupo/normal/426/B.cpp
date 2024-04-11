#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int main() {
    int n, m;
    cin >> n >> m;
    int d[110][110];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }
    int u = n;
    while (!(u%2)) {
        bool f = true;
        for (int i = 0; i < u/2; i++) {
            for (int j = 0; j < m; j++) {
                if (d[i][j] != d[u-i-1][j]) f = false;
            }
        }
        if (!f) break;
        u /= 2;
    }
    cout << u << endl;
    return 0;
}