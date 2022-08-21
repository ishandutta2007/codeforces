#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
typedef long long ll;

typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 210;
int a[MN];
int main() {
    int n, K;
    cin >> n >> K;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int r = -10000000;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            vector<int> v1, v2;
            for (int k = 0; k < n; k++) {
                if (i <= k && k < j) {
                    v1.push_back(a[k]);
                } else {
                    v2.push_back(a[k]);
                }
            }
            sort(v2.begin(), v2.end(), greater<int>());
            for (int k = 0; k < min((int)v2.size(), K); k++) {
                v1.push_back(v2[k]);
            }
            sort(v1.begin(), v1.end(), greater<int>());
            int l = 0;
            for (int k = 0; k < (j-i); k++) {
                l += v1[k];
            }
            r = max(r, l);
        }
    }
    cout << r << endl;
    return 0;
}