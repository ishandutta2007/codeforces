#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef vector<long long> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    long long n,m,k;
    cin >> n >> m >> k;
    vi res(m, 10000000);
    for (int i = 0; i < n; ++i) {
        long long row, c;
        cin >> row >> c;
        res[row - 1] = min (res[row - 1], c);
    }
    long long sum = 0;
    for (int i = 0; i < res.size(); ++i)
        sum += res[i];
    cout << min (sum, k);
    return 0;
}