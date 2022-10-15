#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, m;
    cin >> n >> m;
    vvi v(n, vi(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
        scanf("%d", &v[i][j]);
    bool go = 1;
    vi hor(n, 1), ver(m, 1);
    while (go) {
        go = 0;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < m; ++j)
                sum += v[i][j] * ver[j];
            if (sum * hor[i] < 0) {
                hor[i] = -hor[i];
                go = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j)
                sum += v[j][i] * hor[j];
            if (sum * ver[i] < 0) {
                ver[i] = -ver[i];
                go = 1;
            }
        }
    }
    vi ans1;
    for (int i = 0; i < hor.size(); ++i) if (hor[i] == -1)
        ans1.push_back(i + 1);
    cout << ans1.size();
    for (int i = 0; i < ans1.size(); ++i)
        cout << " " << ans1[i];
    cout << endl;
    vi ans2;
    for (int i = 0; i < ver.size(); ++i) if (ver[i] == -1)
        ans2.push_back(i + 1);
    cout << ans2.size();
    for (int i = 0; i < ans2.size(); ++i)
        cout << " " << ans2[i];
    return 0;
}