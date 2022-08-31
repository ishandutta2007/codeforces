#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

int main() {
    int n;
    cin >> n;
    if (n == 2) cout << 2 << endl;
    else cout << 1 << endl;
    return 0;
}