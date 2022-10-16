#include <bits/stdc++.h>
using namespace std;
int n;
int c[200001];
int a[200001];
int cnt_zero[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int done = 0;
    int last_good = 0;
    bool first_zeros = true;
    for (int i = 1; i <= n; i++) {
        if (done < i) {
            assert(first_zeros);
            done = i;
            if (c[i] > 0) {
                a[i] = 1;
                cnt_zero[i] = i - 1;
                first_zeros = 0;
            } else {
                a[i] = 0;
                cnt_zero[i] = i;
            }
            done = i;
        }
        if (first_zeros) continue;

        c[i] -= a[i] * (i - 1);
        assert(c[i] >= 0);
        while ((last_good < done) && (cnt_zero[last_good + 1] < i)) last_good++;
        c[i] -= last_good - i + 1;
        assert(c[i] >= 0);
        while (c[i]) {
            done++;
            c[i]--;
            a[done] = 1;
            cnt_zero[done] = cnt_zero[done - 1];  // these value must be one otherwise we can't reach the sum
        }
        assert(done <= n);
        if (done < n) {
            done++;
            a[done] = 0;
            cnt_zero[done] = cnt_zero[done - 1] + 1;  // this value must be zero otherwise we go pass this sum
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}