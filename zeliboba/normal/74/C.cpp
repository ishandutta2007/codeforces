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

int gcd (int n, int m) {
    while (m) {
        n %= m;
        swap(n, m);
    }
    return n;
}

int main() {
    int n, m;
    cin >> n >> m;
    int d = gcd(n - 1, m - 1);
    cout << d + 1 << endl;
    return 0;
}