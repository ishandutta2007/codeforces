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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

ll calc(string s) {
    int n = int(s.size());
    if (n == 1) {
        if (s[0] == '9') {
            return 1989;
        } else {
            return 1990 + s[0]-'0';
        }
    }

    ll u = calc(s.substr(1));

    u += TEN(n-1);
    while (true) {
        if (u / TEN(n-1) % 10 == s[0]-'0') break;
        u += TEN(n-1);
    }
    return u;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s = s.substr(4);
        cout << calc(s) << endl;
    }
    return 0;
}