#include <bits/stdc++.h>
using namespace std;
int n;
string s;
constexpr int64_t base[] = {31, 37, 41};
constexpr int64_t mod[] = {617919427, 999727999, 1'000'000'007};
class HashInt {
  public:
    inline static constexpr int count = 3;
    int64_t a[count];

    HashInt() {
        for (int i = 0; i < count; i++) a[i] = 0;
    }

    int64_t& operator[](const int& idx) { return a[idx]; }
    const int64_t& operator[](const int& idx) const { return a[idx]; }

    HashInt TimeBase() const {
        HashInt ans = *this;
        for (int i = 0; i < count; i++) (ans[i] *= base[i]) %= mod[i];
        return ans;
    }

    HashInt AddChar(char c) const {
        HashInt ans = *this;
        for (int i = 0; i < count; i++) (ans[i] += c) %= mod[i];
        return ans;
    }

    bool operator==(const HashInt& other) const {
        for (int i = 0; i < count; i++) {
            if ((a[i] - other[i]) % mod[i]) return false;
        }
        return true;
    }

    HashInt operator*(const HashInt& other) const {
        HashInt ans = *this;
        for (int i = 0; i < count; i++) {
            (ans[i] *= other[i]) %= mod[i];
        }
        return ans;
    }

    HashInt operator-(const HashInt& other) const {
        HashInt ans = *this;
        for (int i = 0; i < count; i++) {
            (ans[i] -= other[i]) %= mod[i];
            if (ans[i] < 0) ans[i] += mod[i];
        }
        return ans;
    }
};

HashInt h[500000];
HashInt rh[500000];
HashInt p[500001];
HashInt get_hash(int l, int r) { return h[r] - ((l ? h[l - 1] : HashInt()) * p[r - l + 1]); }
HashInt get_rhash(int l, int r) { return rh[l] - (((r + 1 < n) ? rh[r + 1] : HashInt()) * p[r - l + 1]); }
bool is_palindome(int l, int r) {
    auto forward = get_hash(l, r);
    auto backward = get_rhash(l, r);
    // cerr << "l, r: " << l << ' ' << r << '\n';
    // for (int i = 0; i < HashInt::count; i++) {
    //     cerr << forward[i] << ' ' << backward[i] << '\n';
    // }
    // cerr << '\n';
    return forward == backward;
}
void solve() {
    cin >> n >> s;
    for (auto&& x : s)
        if (x == '(')
            x = 'a';
        else
            x = 'b';
    if (s.size() == 1) {
        cout << "0 1\n";
        return;
    }
    int opt = 0, left = n;
    h[0] = HashInt().AddChar(s[0]);
    for (int i = 1; i < n; i++) h[i] = h[i - 1].TimeBase().AddChar(s[i]);

    rh[n - 1] = HashInt().AddChar(s[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        rh[i] = rh[i + 1].TimeBase().AddChar(s[i]);
        // cerr << "i: " << i << '\n';
        // for (int j = 0; j < HashInt::count; j++) {
        //     cerr << rh[i][j] << " \n"[j + 1 == HashInt::count];
        // }
    }

    for (int i = 1; i < n; i += 2) {
        if ((s[i] == 'b') || (s[i - 1] == 'a')) {
            left = n - i - 1;
        opt++;
        } else {
            int j = i;
            while ((j < n) && (!is_palindome(i - 1, j))) j++;
            if (j == n) {
                break;
            } else {
        opt++;
                i = j;
                left = n - i - 1;
            }
        }
    }
    cout << opt << ' ' << left << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int i = 0; i < 3; i++) p[0][i] = 1;
    for (int i = 1; i <= 500000; i++) p[i] = p[i - 1].TimeBase();
    cin >> t;
    while (t--) solve();
}