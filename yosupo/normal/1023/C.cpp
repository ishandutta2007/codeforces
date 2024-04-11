#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    cout << "[";
    for (auto p: v) cout << p << ", ";
    cout << "]";
    return os;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    V<int> idx;
    int cnt;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            idx.push_back(i);
            cnt++;
            if (cnt == k/2) break;
        }
    }
    cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == ')') {
            idx.push_back(i);
            cnt++;
            if (cnt == k/2) break;
        }
    }
    sort(idx.begin(), idx.end());

    string ans;
    for (int d: idx) ans += s[d];

    cout << ans << endl;

    return 0;
}