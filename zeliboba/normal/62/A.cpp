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

bool f (int b, int a) {
    if (a < b - 1 || b < (a + 1) / 2 - 1)
        return false;
    else return true;
}

int main() {
    int nl, nr, ml, mr;
    cin >> nl >> nr >> ml >> mr;
    if (f(nl, mr) || f(nr, ml))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}