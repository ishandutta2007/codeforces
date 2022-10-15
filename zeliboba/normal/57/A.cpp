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
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int d(int a, int b, int a1, int b1) {
    return abs(a - a1) + abs(b - b1);
}

int main() {
    int n;
    cin >> n;
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2 && (y1 == 0 || y1 == n)) {
        cout << abs(x1 - x2) << endl;
        return 0;
    }
    if (x1 == x2 && (x1 == 0 || x1 == n)) {
        cout << abs(y1 - y2) << endl;
        return 0;
    }
    if (abs(y1 - y2) == n) {
        swap(x1, y1);
        swap(x2, y2);
    } 
    if (abs(x1 - x2) == n) {
        cout << n + min(y1 + y2, 2 * n - y1 - y2) << endl;
        return 0;
    }
    int mi = 2 * n;
    for (int i = 0; i <= n; i += n) for (int j = 0; j <= n; j += n) {
        mi = min(mi, d(x1, y1, i, j) + d(x2, y2, i, j));
    }
    cout << mi << endl;
    return 0;
}