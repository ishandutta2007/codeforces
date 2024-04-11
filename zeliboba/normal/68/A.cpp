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
    vi p(4); int a, b, res = 0;
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
    for (int n = a; n <= b; ++n) {
        int tr = 1;
        for (int i = 0; i < 4; ++i)
            if (p[i] <= n)
                tr = 0;
        res += tr;
    }
    printf("%d\n", res);
    return 0;
}