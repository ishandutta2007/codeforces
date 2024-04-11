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
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int N;
VV<bool> rev(VV<bool> v) {
    reverse(begin(v), end(v));
    return v;
}

VV<bool> rot(VV<bool> v) {
    VV<bool> v2(N, V<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v2[i][N-1-j] = v[j][i];
        }
    }
    return v2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    cin >> N;
    VV<bool> v1(N, V<bool>(N)), v2(N, V<bool>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            v1[i][j] = s[j] == 'O';
        }
    }
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            v2[i][j] = s[j] == 'O';
        }
    }

    for (int i = 0; i < 5; i++) {
        v1 = rot(v1);
        if (v1 == v2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    v1 = rev(v1);
    for (int i = 0; i < 5; i++) {
        v1 = rot(v1);
        if (v1 == v2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}