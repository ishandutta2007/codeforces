#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
 
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << 2*(a+b)*(b+c) - (b*b) - (e*e) << endl;
    return 0;
}