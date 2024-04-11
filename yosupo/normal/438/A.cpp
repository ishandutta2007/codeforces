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
    int d[1010];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    ll res = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        res += min(d[a], d[b]);
    }
    cout << res << endl;
    return 0;
}