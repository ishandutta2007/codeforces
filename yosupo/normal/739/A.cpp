#include <iostream>
#include <cstdio>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }


int main() {
//    freopen("Ain1.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int ma = 10*n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ma = min(ma, b-a+1);
    }
    cout << ma << endl;
    for (int i = 0; i < n; i++) {
        cout << i % ma << " ";
    } cout << endl;
    return 0;
}