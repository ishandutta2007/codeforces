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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, m;
    cin >> n >> m;
    --m;
    int s,f,t;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &s, &f, &t);
        --s; --f;
        int t1 = t % (2 * m);
        if (s < f) {
            if (t1 > s)
                t += f + 2 * m - t1;
            else t += f - t1;
        } else if (s > f) {
            if (t1 > 2 * m - s)
                t += 2 * m - f - t1 + 2 * m;
            else t += 2 * m - f - t1;
        }
        printf("%d\n", t);
    }
    return 0;
}