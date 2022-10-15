#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//-----------------------------------------------
// #define LOG
#ifdef LOG
    #define db(x)     cerr << #x << ": " << x << endl;
    #define dbA(x, s) cerr << #x << ": "; for (int i = 0; i < s; i++) cerr << x[i] << " "; cerr << endl;
#else
    #define db(x)
    #define dbA(x, s)
#endif
//-----------------------------------------------
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//-----------------------------------------------
template<class K, class V> ostream& operator << (ostream& out, const pair<K, V>& obj) { out << "{ " << obj.first << ", " << obj.second << " }"; return out; }
template<class T> ostream& operator << (ostream& out, const vector<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const deque<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const set<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const unordered_set<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const ordered_set<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const ordered_multiset<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class K, class V> ostream& operator << (ostream& out, const map<K, V>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class K, class V> ostream& operator << (ostream& out, const unordered_map<K, V>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
//-----------------------------------------------
#define all(x)  x.begin(), x.end()
#define sz(x)   (int)x.size()
#define sq(x)   (x) * (x)
#define fr      first
#define sc      second
#define newline puts("")
//-----------------------------------------------
using ll = long long;
using ld = long double;
//-----------------------------------------------
const int N   = 300 * 1000 + 5;
const ll mod  = 1000000007;
const ll mod3 = 998244353;
const ll INFL = 2000000000 * 1ll * 1000000000 + 500000;
const ll INF  = 1000000000;
const ld pi   = acosl(-1.0);
//-----------------------------------------------

int n, m;
vector<ll> d;
vector<ll> fact, inv_fact;

int binpow(int a, int n) {
    if (n == 0) return 1;
    return (n & 1) ? a * 1ll * binpow(a, n - 1) % mod3 : binpow(a * 1ll * a % mod3, n >> 1);
}

int bininv(int a) {
    return binpow(a, mod3 - 2);
}

void preprocess() {
    fact.resize(N + 1);
    inv_fact.resize(N + 1);

    fact[0] = inv_fact[0] = 1;

    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * 1ll * i % mod3;
        inv_fact[i] = bininv(fact[i]);
    }
}

int A(int n, int k) {
    return fact[n] * 1ll * inv_fact[n - k] % mod3;
}

int C(int n, int k) {
    return A(n, k) * 1ll * inv_fact[k] % mod3;
}

void input() {
    scanf("%d%d", &n, &m);
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
}

ll num_col_diff(int n, int k, int p) {
    // n - lamps, k - num of pairs, p - num of colors
    if (k == 0) return binpow(p, n);
    if (p >= 2) return binpow(p, n - k) * 1ll * binpow(p - 1, k) % mod3;
    if (p == 1) return k == 0 ? 1 : 0;
    if (p == 0) return n == 0 ? 1 : 0;
    return 0;
}

void solve(int test_id) {
    ll sm = 0;
    vector<ll> pref_sum(n, 0);

    for (int i = 0; i < n; i++) {
        sm += d[i];
        pref_sum[i] = (i == 0 ? 0 : pref_sum[i - 1] + d[i - 1]);
    }

    ll ans = 0;

    if (sm % 2 == 1) {
        ans = binpow(m, n);
    } else {
        int k = 0;
        sm /= 2;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && pref_sum[i] + sm > pref_sum[j]) {
                j++;
            }
            if (j < n && pref_sum[i] + sm == pref_sum[j]) {
                k++;
            }
        }

        for (int i = 0; i <= min(m, k); i++) {
            int coeff = C(k, i) * 1ll * A(m, i) % mod3;
            ans += coeff * 1ll * num_col_diff(n - 2 * i, k - i, m - i) % mod3;
            ans %= mod3;
        }
    }
    cout << ans << endl;
}

int main() {
    int testcases = 1;
    preprocess();
    // scanf("%d", &testcases);
    for(int test_id = 1; test_id <= testcases; test_id++) {
        input();
        solve(test_id);
    }
    return 0;
}