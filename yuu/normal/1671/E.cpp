#include <bits/stdc++.h>
using namespace std;
int n, max_node;
string s;
class Hash {
public:
    static constexpr int MOD_COUNT = 4;
    static constexpr int N = 1 << 18;
    static constexpr int64_t MOD[] = {999'727'999, 999'999'937, 1'000'000'9, 998'244'353};
    static constexpr int BASE[] = {31, 37, 43, 131};
    inline static int64_t p[MOD_COUNT][N + 1];
    inline static bool initialized = false;
    inline static void Initialize() {
        initialized = true;
        for (int i = 0; i < MOD_COUNT; i++) {
            p[i][0] = 1;
            for (int j = 1; j <= N; j++) {
                (p[i][j] = p[i][j - 1] * BASE[i]) %= MOD[i];
            }
        }
    }

    int64_t hash[MOD_COUNT];
    int length;
    Hash(char c) {
        if (!initialized) Initialize();
        length = 1;
        for (int i = 0; i < MOD_COUNT; i++) (hash[i] = c) %= MOD[i];
    }

    Hash(const Hash &A, const Hash &B) {
        if (!initialized) Initialize();
        length = A.length + B.length;
        for (int i = 0; i < MOD_COUNT; i++) {
            (hash[i] = A.hash[i] * p[i][B.length] + B.hash[i]) %= MOD[i];
        }
    }

    Hash operator+(const Hash &other) const { return Hash(*this, other); }

    bool operator==(const Hash &other) const {
        for (int i = 0; i < MOD_COUNT; i++)
            if (hash[i] != other.hash[i]) return 0;
        return 1;
    }

    bool operator<(const Hash &other) const {
        for (int i = 0; i < MOD_COUNT; i++)
            if (hash[i] != other.hash[i]) return hash[i] < other.hash[i];
        return 0;
    }
};
constexpr int base = 998'244'353;
pair<int64_t, Hash> solve(int node) {
    if (node * 2 > max_node) {  // left
        return {1, Hash(s[node])};
    } else {
        auto [cnt_left, hash_left] = solve(node * 2);
        auto [cnt_right, hash_right] = solve(node * 2 + 1);
        int64_t cnt = 1;
        if (hash_left == hash_right) {
            (cnt = cnt_left * cnt_right) %= base;
        } else {
            (cnt = cnt_left * cnt_right * 2) %= base;
        }
        Hash hash(s[node]);
        if (hash_left < hash_right) {
            hash = hash + hash_left;
            hash = hash + hash_right;
        } else {
            hash = hash + hash_right;
            hash = hash + hash_left;
        }
        return {cnt, hash};
    }
}
void solve() {
    cin >> n;
    cin >> s;
    s = '0' + s;
    max_node = (1 << n) - 1;
    auto [cnt, hash] = solve(1);
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}