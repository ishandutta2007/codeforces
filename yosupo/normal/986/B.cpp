#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T>
struct Fenwick {
    int n;
    V<T> seg;
    Fenwick() {}
    Fenwick(int n) : n(n) {
        seg = V<T>(n+1, T(0));
    }
    /// ix
    void add(int i, T x) {
        i++;
        while (i <= n) {
            seg[i] += x;
            i += i & -i;
        }
    }
    /// [0, i)sum
    T sum(int i) {
        T s{0};
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) {
        return sum(b) - sum(a);
    }
};

int calc(V<int> a) {
    int n = int(a.size());
    Fenwick<int> fw(n);
    int z = 0;
    for (int d: a) {
        z += fw.sum(d, n); z %= 2;
        fw.add(d, 1);
    }
    return z;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;
    V<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    int z = calc(a);
    int f = n % 2;

    if (z == f) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
    }
    return 0;
}