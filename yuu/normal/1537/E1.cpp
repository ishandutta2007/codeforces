#include <bits/stdc++.h>
using namespace std;

constexpr int64_t base[] = {31, 37, 41};
constexpr int64_t mod[] = {999'999'937, 999'727'999, 1'000'000'007};
class HashInt {
  public:
    inline static constexpr int count = 3;
    int64_t a[count];

    HashInt(bool unit = false) {
        for (int i = 0; i < count; i++) a[i] = unit;
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

    HashInt operator+(const HashInt& other) const {
        HashInt ans = *this;
        for (int i = 0; i < count; i++) {
            (ans[i] += other[i]) %= mod[i];
        }
        return ans;
    }
};

HashInt h[500000];
HashInt p[500001];
HashInt compound_hash(const HashInt& left_hash, const HashInt& right_hash, const int length_right) {
    return left_hash * p[length_right] + right_hash;
}

class StringRepresentation {
  public:
    HashInt hash;
    int length;

    StringRepresentation(const HashInt& hash = HashInt(), const int length = 0) : hash(hash), length(length) {}

    StringRepresentation Double() {
        StringRepresentation res = (*this);
        res.hash = compound_hash(res.hash, hash, length);
        res.length *= 2;
        return res;
    }

    StringRepresentation Append(const StringRepresentation& other) {
        StringRepresentation res = (*this);
        res.hash = compound_hash(res.hash, other.hash, other.length);
        res.length += other.length;
        return res;
    }
};

StringRepresentation get_power(const StringRepresentation& x, int cnt) {
    if (cnt == 0) return StringRepresentation();
    if (cnt == 1) return x;
    auto res = get_power(x, cnt / 2);
    res = res.Double();
    if (cnt % 2) res = res.Append(x);
    return res;
}

StringRepresentation get_repeated_prefix_hash(int prefix, int length) {
    int cnt = length / (prefix + 1);
    auto res = get_power(StringRepresentation(h[prefix], prefix + 1), cnt);
    cnt = length % (prefix + 1);
    if (cnt) res = res.Append(StringRepresentation(h[cnt - 1], cnt));
    return res;
}

int n, k;
string s;
char first;
int ans_prefix;

char get_repeated_prefix_char(int prefix, int pos) { return s[pos % (prefix + 1)]; }

void test(int prefix) {
    int low = 1, high = k, mid, res = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (get_repeated_prefix_hash(prefix, mid).hash == get_repeated_prefix_hash(ans_prefix, mid).hash) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (res == k) return;
    if (get_repeated_prefix_char(prefix, res) < get_repeated_prefix_char(ans_prefix, res)) {
        ans_prefix = prefix;
    }
}

void solve() {
    cin >> n >> k;
    cin >> s;
    first = s[0];

    h[0] = HashInt().AddChar(s[0]);
    while (s.size() > k) s.pop_back();

    for (int i = 1; i < s.size(); i++) h[i] = h[i - 1].TimeBase().AddChar(s[i]);
    for (int i = 0; i < 3; i++) p[0][i] = 1;
    for (int i = 1; i <= k; i++) p[i] = p[i - 1].TimeBase();

    for (int i = 1; i < s.size(); i++) test(i);

    while (s.size() > ans_prefix + 1) s.pop_back();
    while (s.size() < k) s += s;
    while (s.size() > k) s.pop_back();
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}