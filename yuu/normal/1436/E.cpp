#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
bool good[100003];
int last[100003];
vector<pair<int, int>> query;
constexpr int BUCKET_SIZE = 256;
int cnt[100003];
bool inq[100003];
priority_queue<int, vector<int>, greater<int>> possible;
int mex = 0;
void update_mex() {
    mex = possible.top();
    while (cnt[mex]) {
        inq[mex] = 0;
        possible.pop();
        mex = possible.top();
    }
}
void add(int x) {
    cnt[x]++;
    update_mex();
}
void remove(int x) {
    cnt[x]--;
    if (cnt[x] == 0) {
        if (!inq[x]) {
            inq[x] = 1;
            possible.push(x);
        }
    }
    update_mex();
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > last[a[i]] + 1) query.emplace_back(last[a[i]] + 1, i - 1);
        last[a[i]] = i;
    }
    for (int i = 1; i <= n + 1; i++) {
        if (last[i] == n) continue;
        query.emplace_back(last[i] + 1, n);
    }
    sort(query.begin(), query.end(), [](const auto& A, const auto& B) {
        if (A.second / BUCKET_SIZE != B.second / BUCKET_SIZE) {
            return A.second / BUCKET_SIZE < B.second / BUCKET_SIZE;
        } else {
            if ((A.second / BUCKET_SIZE) % 2) {
                return A.first > B.first;
            } else {
                return A.first < B.first;
            }
        }
    });
    for (int i = 1; i <= n + 2; i++) {
        inq[i] = 1;
        possible.push(i);
    }
    mex = n + 1;
    int l = 1, r = 1;
    add(a[1]);
    for (auto&& [x, y] : query) {
        while (l > x) {
            l--;
            add(a[l]);
        }
        while (r < y) {
            r++;
            add(a[r]);
        }
        while (l < x) {
            remove(a[l]);
            l++;
        }
        while (r > y) {
            remove(a[r]);
            r--;
        }
        good[mex] = 1;
    }
    for (int i = 1; i <= n + 2; i++)
        if (!good[i]) {
            cout << i << '\n';
            return;
        }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}