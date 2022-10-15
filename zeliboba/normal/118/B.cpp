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
    int n;
    cin >> n;
    for (int i = 0; i <= 2 * n; ++i) {
        int i1 = abs(i - n);
        for (int j = 0; j < 2 * i1; ++j)
            cout << ' ';
        cout << 0;
        for (int j = 1; j + i1 <= n; ++j)
            cout << ' ' << j;
        for (int j = n - i1 - 1; j >= 0; --j)
            cout << ' ' << j;
        cout << endl;
    }
    return 0;
}