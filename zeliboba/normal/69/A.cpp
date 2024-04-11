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
    int n;
    cin >> n;
    long long x, y, z, a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> z;
        a += x;
        b += y;
        c += z;
    }
    if (a || b || c) printf("NO\n");
    else printf("YES\n");
    return 0;
}