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

char a[55][55], b[55][55];

int main() {
    int n1, m1, n2, m2;
    cin >> n1 >> m1;
    for (int i = 0; i < n1; ++i)
        scanf("%s", a[i]);
    cin >> n2 >> m2;
    for (int i = 0; i < n2; ++i)
        scanf("%s", b[i]);
    int ma = 0, bx = 0, by = 0;
    for (int x = -50; x <= 50; ++x) for (int y = -50; y <= 50; ++y) {
        int cnt = 0;
        for (int i = max(0, -x); i < min(n1, n2 - x); ++i) for (int j = max(0, -y); j < (m1, m2 - y); ++j)
            if (a[i][j] == '1' && b[i + x][j + y] == '1')
                ++cnt;
        if (cnt > ma) {
            ma = cnt;
            bx = x;
            by = y;
        }
    }
    cout << bx << " " << by << endl;
    return 0;
}