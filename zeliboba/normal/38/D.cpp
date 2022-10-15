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
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

long long p3 (int x) {
    if (x > 0)
        return x * x * x;
    else
        return -x*x*x;
}

int main() {
    int n;
    cin >> n;
    vector<pii> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i].first >> v1[i].second >> v2[i].first >> v2[i].second;
        int mi = min(v1[i].first, v2[i].first);
        v2[i].first = max(v1[i].first, v2[i].first);
        v1[i].first = mi;
        mi = min(v1[i].second, v2[i].second);
        v2[i].second = max(v1[i].second, v2[i].second);
        v1[i].second = mi;
    }
    int maxh = 1;
    bool tr = true;
    for (int i = 1; i < n; ++i) {
        for (int t = 0; t < i; ++t) {
            pll resx(0, 0), resy(0, 0);
            for (int j = t + 1; j <= i; ++j) {
                int v = p3(v1[j].first - v2[j].first);
                resx.first += (v1[j].first + v2[j].first) * v;
                resx.second += 2 * v;
                resy.second += 2 * v;
                resy.first += (v1[j].second + v2[j].second) * v;
            }
            if (!(v1[t].first * resx.second <= resx.first && v2[t].first * resx.second >= resx.first &&
                    v1[t].second * resx.second <= resy.first && v2[t].second * resy.second >= resy.first)) {
                tr = false;
                break;
            }
        }
        if (tr)
            ++maxh;
        else
            break;
    }
    cout << maxh << endl;
    return 0;
}