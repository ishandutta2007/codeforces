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
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    string ss, tt;
    cin >> ss >> tt;
    set<string> s;
    s.insert(ss); s.insert(tt);
    auto pr = [&]() {
        for (string ss: s) {
            cout << ss << " ";
        }
        cout << endl;
    };
    int n;
    cin >> n;
    pr();
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        s.erase(a); s.insert(b);
        pr();
    }
    return 0;
}