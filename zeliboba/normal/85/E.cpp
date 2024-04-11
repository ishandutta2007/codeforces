#include <cstdio>
#include <cstdlib>
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

const int mod = 1e9 + 7;
int dist[5001][5001];

int mpow (ll x, int n) {
    ll res = 1;
    while (n) {
        if (n % 2)
            res = (res * x) % mod;
        n /= 2;
        x = (x * x) % mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    if (n == 2) {
        printf("0 2\n");
        return 0;
    }
    vi x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    int l = 0, r = 10000, cnt = 0;
    while (r - l > 1) {
        int x = (l + r) / 2;
//        cerr << x << " " << l << " " << r << endl;
        vector<char> was(n, 0);
        int it = 0;
        int cur = 0;
        vi queue;
        bool ok = 1;
        cnt = 0;
        while (cur < n) {
            if (!was[cur]) {
                ++cnt;
                was[cur] = 1;
                queue.push_back(cur);
                while (it < queue.size()) {
                    for (int i = 0/*queue[it] + 1*/; i < n; ++i) if (dist[queue[it]][i] > x) {
//                        cerr << queue[it] << " -> " << i << " " << (int)was[i] << " " << (int)was[queue[it]] << endl;
                        if (!was[i]) {
                            was[i] = 3 - was[queue[it]];
                            queue.push_back(i);
                        } else if (was[i] == was[queue[it]]) {
                            ok = 0;
                            break;
                        }
                    }
                    if (!ok)
                        break;
                    ++it;
                }
            }
            if (!ok)
                break;
            ++cur;
        }
        if (!ok) {
            l = x;
        } else r = x;
        if (l == x && l == r - 1)
            ++r;
    }
    cout << r << " " << mpow(2, cnt) << endl;
    return 0;
}