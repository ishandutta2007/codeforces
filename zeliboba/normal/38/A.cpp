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
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vi d(n - 1);
    for (int i = 0; i < n - 1; ++i)
        cin >> d[i];
    int a,b;
    cin >> a >> b;
    if (b <= a) {
        cout << 0 << endl;
        return 0;
    }
    int res = 0;
    for (int i = a - 1; i < b - 1; ++i)
        res += d[i];
    cout << res << endl;
    return 0;
}