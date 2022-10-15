#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int n;
int a[200005];

void solve(int test_ind) {
    cin >> n;
    unordered_map<int, int> min_index;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    int st_bl = 0;

    min_index[0] = 2 * n;
    for (int i = 2 * n - 1; i >= n; i--) {
        if (a[i] == 1) {
            st_bl++;
        }
        else {
            st_bl--;
        }
        min_index[st_bl] = i;
    }


    st_bl = 0;
    int ans = min_index[0];
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            st_bl++;
        }
        else {
            st_bl--;
        }
        if (min_index.find(-st_bl) != min_index.end()) {
            ans = min(min_index[-st_bl] - i - 1, ans);
        }
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
    return 0;
}