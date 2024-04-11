#include <bits/stdc++.h>
using namespace std;

class XorEngine {
  public:
    int k;
    vector<int> internal;
    vector<int> external;
    int original;

    explicit XorEngine(const int &k) : k(k), original(1) {}

    void Make(int value) {
        external.clear();
        while (value > 0) {
            external.push_back(value % k);
            value /= k;
        }
        while (internal.size() < external.size()) internal.push_back(0);
        while (external.size() < internal.size()) external.push_back(0);
    }

    int Get(int value) {
        Make(value);
        for (int i = 0; i < internal.size(); i++)
            if (original == 1)
                (external[i] += internal[i]) %= k;
            else
                (external[i] = internal[i] + k - external[i]) %= k;

        int ans = 0;
        int weight = 1;
        for (int i = 0; i < external.size(); i++) {
            ans += external[i] * weight;
            weight *= k;
        }
        return ans;
    }

    void Update(int value) {
        Make(value);
        original = -original;
        for (int i = 0; i < internal.size(); i++) (internal[i] = external[i] + k - internal[i]) %= k;
    }
};

bool guess(int y) {
    cout << y << '\n';
    cout.flush();
    cin >> y;
    return (y == 1);
}
int n, k;

void solve() {
    cin >> n >> k;
    XorEngine engine(k);
    for (int i = 0; i < n; i++) {
        int y = engine.Get(i);
        if (guess(y)) break;
        engine.Update(y);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}