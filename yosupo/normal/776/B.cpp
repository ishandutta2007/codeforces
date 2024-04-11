#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 1 << endl << "1 1" << endl;
        return 0;
    }
    cout << 2 << endl;
    for (int i = 2; i < n+2; i++) {
        bool f = false;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                f = true;
                break;
            }
        }
        if (f) {
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    }
    cout << endl;
    return 0;
}