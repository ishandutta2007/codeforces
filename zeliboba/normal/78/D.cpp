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
    i64 k;
    cin >> k;
    long long cnt = 0;
    for (double a = 2 + 2./3; a < (2 * k) / sqrt(3); a += 2) {
        double b = 1e-8 + (-a + sqrt((16 * k * k) / 3. - (3 * a * a))) / 2. - 2. / 3;
//        cerr << a << " " << b << " " << (int)b << endl;
        if (b > 0)
            cnt += ((int)b + 2) / 2;
    }
    cout << 1 + 6 * cnt << endl;
    return 0;
}