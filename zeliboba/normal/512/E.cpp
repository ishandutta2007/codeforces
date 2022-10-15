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
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

void in(vvi & v) {
    int n = v.size();
    for (int i = 0; i + 3 < v.size(); ++i) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    for (int i = 0; i < n; ++i) {
        v[i][(i+1)%n] = 1;
        v[(i+1)%n][i] = 1;
    }
}

vvi f(vvi v) {
    vvi res;
    vi x(4);
    int n = v.size();
    for (int i = 2; i < n-1; ++i) if (!v[0][i]) {
        assert(v[i-1][0] == 1);
        for (int j = i + 1; j < n; ++j) if (v[0][j]) {
            assert(v[i-1][j] == 1);
            for (int l = i; l < j; ++l) if (v[l][j]) {
                assert(v[0][l] == 0);
                assert(v[i-1][l] == 1);
                v[i-1][j] = v[j][i-1] = 0;
                v[0][l] = v[l][0] = 1;
                x[0] = i-1; x[1] = j; x[2] = 0; x[3] = l;
                res.push_back(x);
                break;
            }
            break;
        }
        --i;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vvi v1(n, vi(n)), v2(n, vi(n));
    in(v1);
    in(v2);
    vvi a = f(v1);
    vvi b = f(v2);
    cout << a.size() + b.size() << endl;
    for (int i = 0; i < a.size(); ++i)
        cout << a[i][0]+1 << ' ' << a[i][1] + 1 << endl;
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); ++i)
        cout << b[i][2]+1 << ' ' << b[i][3] + 1 << endl;
    return 0;
}