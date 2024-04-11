#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 101000;
ll d[MN];
ll ld[MN], rd[MN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 2 << endl;
        return 0;
    }
    int i = 0;
    while (i < n) {
        ld[i] = 1;
        int j;
        for (j = i+1; j < n; j++) {
            if (d[j-1] < d[j]) {
                ld[j]= j-i+1;
            } else {
                break;
            }
        }
        i = j;
    }
    i = n-1;
    while (i >= 0) {
        rd[i] = 1;
        int j;
        for (j = i-1; j >= 0; j--) {
            if (d[j] < d[j+1]) {
                rd[j] = i-j+1;
            } else {
                break;
            }
        }
        i = j;
    }
    ll r = 0;
    for (int i = 0; i < n; i++) {
        r = max(r, max(ld[i], rd[i]));
    }
    r = max(r, ld[n-2]+1);
    r = max(r, rd[1]+1);
    for (int i = 1; i < n-1; i++) {
        if (d[i+1]-d[i-1] > 1) {
            r = max(r, ld[i-1]+rd[i+1]+1);
        } else {
            r = max(r, max(ld[i-1]+1, rd[i+1]+1));
        }
    }
    cout << r << endl;
    return 0;
}