//#define NDEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>

using namespace std;
 

const int MN = 550;
const int MM = 1100;
int w[MN], b[MM];
int ord[MN], oc;
bool used[MN];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i]; b[i]--;
        if (!used[b[i]]) {
            used[b[i]] = true;
            ord[oc] = b[i];
            oc++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            ord[oc] = i;
            oc++;
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (ord[j] == b[i]) {
                res += sum;
                for (int k = j; k >= 1; k--) {
                    ord[k] = ord[k-1];
                }
                ord[0] = b[i];
                break;
            }
            sum += w[ord[j]];
        }
    }
    cout << res << endl;
}