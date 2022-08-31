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

int main() {
    string s;
    cin >> s;
    bool alla = true;
    for (char c: s) {
        if (c != 'a') {
            alla = false;
            break;
        }
    }
    if (alla) {
        s.back() = 'z';
    } else {
        bool f = true;
        for (char &c: s) {
            if (c == 'a') {
                if (f) continue;
                else break;
            }
            f = false;
            c -= 1;
        }
    }
    cout << s << endl;
    return 0;
}