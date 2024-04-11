#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const  ll mod = 1000000007;
const int ZVALUE_SIZE = 1000006 + 106;
const int N = 100006;
struct Z_VALUE {
	string s;
	int l, r, z[ZVALUE_SIZE];
	void solve(string _s) {
		s = _s;
        l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i) {
            z[i] = 0;
        }
		for (int i = 0; i < s.size(); ++i) {
			z[i] = max(min(z[i - l], r - i), 0);
			while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
				l = i, r = i + z[i];
				z[i]++;
			}
		}
        // cerr << "s = " << s << endl;
        // for (int i = 0; i < s.size(); ++i) cerr << z[i] << ' '; cerr << endl;
	}
} z1, z2;

int n, q;
string s0, t;
int m; // m = |s0|

int prefix_sum[144][N]; // char, 0-based index

ll pow2[ZVALUE_SIZE];
ll rev_pow2[ZVALUE_SIZE];
ll ans = 0;
int k;
string w;

ll f(string str, int now_level) {
    // cerr << "str = " << str << " , now_level = " << now_level << endl;
    if (now_level > k) return 0;
    if ((int)str.size() == 1) {
        return (prefix_sum[ str[0] ][k - 1] - (now_level == 0 ? 0 : prefix_sum[ str[0] ][now_level - 1]) + mod) * rev_pow2[N - (k - 1)] % mod;
    }
    // return 0;
    ll ret = 0;
    // check odd position
    string odd_str = "", even_str = "";
    bool f1 = true, f2 = true;
    for (int i = 0; i < str.size(); ++i) {
        if (i & 1) odd_str.push_back(str[i]), f1 &= (str[i] == t[now_level]);
        else even_str.push_back(str[i]), f2 &= (str[i] == t[now_level]);
    }
    if (f1) {
        ret += f(even_str, now_level + 1);
    }
    if (f2) {
        ret += f(odd_str, now_level + 1);
    }
    ret %= mod;
    return ret;
}

void solve() {
    cin >> k;
    cin >> w;
    // used z_value
    z1.solve(s0 + "$" + w);
    z2.solve(w + "$" + s0);
    int xx = (int)w.size();
    ans = 0;
    // cerr << "qqqqq" << endl;
    for (int non_s0 = -1; non_s0 <= m; ++non_s0) {
        if (non_s0 >= (int)w.size()) break;
        if (non_s0 == -1) {
            ll tmp_ans = 0;
            for (int i = w.size() + 1; i < xx + 1 + m; ++i) {
                if (z2.z[i] >= w.size()) {
                    tmp_ans++;
                }
            }
            ans += tmp_ans * pow2[k];
            ans %= mod;
            continue;
        }
        // check prefix
        bool pre_ok = true;
        if (non_s0 > 0) {
            if (z2.z[xx + 1 + m - non_s0] == non_s0) ;
            else pre_ok = false;
        }
        if (!pre_ok) continue;
        // cerr << "non_s0 = " << non_s0 << endl;
        // check medium
        int last_j = non_s0 + 1;
        bool medium_ok = true;
        for (int j = non_s0 + 1; j + m <= xx; j += (m + 1)) {
            if (j + m > xx) break;
            if (z1.z[m + 1 + j] < m) {
                medium_ok = false;
                break;
            }
            last_j = j + (m + 1);
        }
        if (!medium_ok) continue;
        // cerr << "non_s1 = " << non_s0 << endl;
        // check suffix
        bool suf_ok = true;
        if (last_j < xx) {
            if (z1.z[last_j + (m + 1)] + last_j != xx) suf_ok = false;
        }
        if (!suf_ok) continue;
        // cerr << "non_s2 = " << non_s0 << endl;
        string new_str = "";
        // collect all non_s0
        for (int j = non_s0; j < xx; j += (m + 1)) {
            new_str.push_back(w[j]);
        }
        // cerr << "new_str = " << new_str << endl;
        ans += f(new_str, 0);
        ans %= mod;
    }
    cout << ans << endl;
}

int main () {
    // z1.solve("abacaba");
    // return 0;
    pow2[0] = 1;
    rev_pow2[0] = 1;
    for (int i = 1; i < ZVALUE_SIZE; ++i) {
        pow2[i] = pow2[i - 1] * 2 % mod;
        rev_pow2[i] = rev_pow2[i - 1] * (500000004) % mod;
        assert(pow2[i] * rev_pow2[i] % mod == 1);
    }
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    cin >> s0 >> t;
    m = (int)s0.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 144; ++j) {
            if (i) prefix_sum[j][i] = prefix_sum[j][i - 1];
            if (j == t[i]) prefix_sum[j][i] = (prefix_sum[j][i] + pow2[N - i]) % mod;
        }
    }
    while (q--) {
        solve();
    }
}