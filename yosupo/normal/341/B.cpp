#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>

using namespace std;
typedef long long ll;


int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    int d[100000];
    int dp[100000];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    fill(dp, dp+n, 1000000);
    for (int i = 0; i < n; i++) {
        *lower_bound(dp, dp+n, d[i]) = d[i];
    }
    cout << lower_bound(dp, dp+n, 1000000) - dp << endl;
    return 0;
}
// CUT end