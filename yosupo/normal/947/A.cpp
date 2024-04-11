#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

const int MN = TEN(6) + 10;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    V<bool> isP(MN, true); isP[0] = isP[1] = false;
    V<int> bk(MN, -1);
    for (int i = 2; i < MN; i++) {
        if (!isP[i]) continue;
        for (int j = 2*i; j < MN; j += i) {
            isP[j] = false;
            bk[j] = i;
        }
    }
    auto factor = [&](int s){
        V<int> v;
        while (s > 1) {
            int p = bk[s];
            v.push_back(p);
            s /= p;
        }
        return v;
    };

    int x2;
    cin >> x2;

    auto v = factor(x2);
    int mp = 1;
    for (int d: v) mp = max(mp, d);

    int x0 = x2;
    int x1_min = x2-mp+1;
    for (int x1 = x1_min; x1 <= x2; x1++) {
        auto v = factor(x1);
        if (v.size() == 1) continue;
        int mp = 1;
        for (int d: v) mp = max(mp, d);
        x0 = min(x0, x1 - mp + 1);
    }
    cout << x0 << endl;
    return 0;
}