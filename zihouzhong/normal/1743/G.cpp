#include <bits/stdc++.h>
using namespace std;

const int fib[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578};
const int P = 998244353;

void norm(int &x) {
    x += x >> 31 & P;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    function<char(int, int)> get = [&](int x, int i) {
        if (!i) return '0';
        if (i == 1) return '1';
        if (x <= fib[i - 1]) return get(x, i - 1);
        return get(x - fib[i - 1], i - 2);
    };
    vector<pair<int, int>> v{{0, 0}}, _v;
    int lst = 1;
    while (n--) {
        string str;
        cin >> str;
        for (char c : str) {
            _v = {{0, 0}};
            if (c == '1' && lst) _v.push_back({1, lst});
            else norm(_v[0].second += lst - P);
            for (auto &[i, x] : v) {
                if (!x) continue;
                if (i && c == get(i + 1, 32)) _v.push_back({i + 1, x});
                else norm(_v[0].second += x - P);
            }
            swap(v, _v);
            int o = lst;
            lst = 0;
            for (auto &[i, x] : v) {
                if (find(fib, fib + 33, i) - fib == 33) {
                    norm(lst += x - P);
                }
            }
            if (c == '0') norm(lst -= o);
        }
        cout << lst << "\n";
    }
    return 0;
}