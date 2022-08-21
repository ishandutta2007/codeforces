#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const int MN = 100100;
bool dp[MN];
int main() {
    int n, m;
    cin >> n >> m;
    n %= m;
    if (n == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    dp[n] = true;
    while (true) {
        n += n%m;
        n %= m;
        if (n == 0) {
            cout << "Yes" << endl;
            return 0;
        }
        if (dp[n]) {
            cout << "No" << endl;
            return 0;
        }
        dp[n] = true;
    }
    return 0;
}