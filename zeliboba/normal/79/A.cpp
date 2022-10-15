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

int main() {
    int x, y;
    cin >> x >> y;
    int t = 0;
    while (y >= 2 && y + 10 * x >= 22) {
        if (t) {
            int cansub = min(y, 22) - 2;
            cansub -= cansub % 10;
            y -= cansub + 2;
            x -= (20 - cansub) / 10;
        } else {
            int cansub = min(2, x);
            x -= cansub;
            y -= 22 - cansub * 10;
        }
        t ^= 1;
    }
    if (!t) {
        cout << "Hanako\n";
    } else cout << "Ciel\n";
    return 0;
}