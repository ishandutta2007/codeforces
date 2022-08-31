#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    /*for (int l = 1; l <= 25; l++) {
        int ma = -1;
        int a = (1<<l) - 1;
        for (int b = 1; b < a; b++) {
            ma = max(ma, gcd(a ^ b, a & b));
        }
        cout << "{" << a << ", " << ma << "}," << endl;
    }*/

    map<int, int> mp = {
            {3, 1},
            {7, 1},
            {15, 5},
            {31, 1},
            {63, 21},
            {127, 1},
            {255, 85},
            {511, 73},
            {1023, 341},
            {2047, 89},
            {4095, 1365},
            {8191, 1},
            {16383, 5461},
            {32767, 4681},
            {65535, 21845},
            {131071, 1},
            {262143, 87381},
            {524287, 1},
            {1048575, 349525},
            {2097151, 299593},
            {4194303, 1398101},
            {8388607, 178481},
            {16777215, 5592405},
            {33554431, 1082401},
    };

    int q;
    cin >> q;
    for (int ph = 0; ph < q; ph++) {
        int a;
        cin >> a;
        if (mp.count(a)) {
            cout << mp[a] << endl;
            continue;
        }
        int x = 1;
        while (x < a) x = 2 * x + 1;
        cout << x << endl;
    }
    return 0;
}