#include <bits/stdc++.h>
using namespace std;
int n, c, q;
string s;
class string_t {
public:
    bool substring;
    string_t *left, *right;
    string_t* raw;
    int64_t l, r;

    int64_t length;

    static string_t* get_substring(string_t* raw, int64_t l, int64_t r) {
        string_t* res = new string_t();
        res->substring = true;
        res->left = res->right = nullptr;
        res->raw = raw;
        res->l = l;
        res->r = r;
        res->length = r - l + 1;
        return res;
    }

    static string_t* combine(string_t* left, string_t* right) {
        string_t* res = new string_t();
        res->substring = false;
        res->left = left;
        res->right = right;
        res->length = left->length + right->length;
        return res;
    }

    static char get_char(string_t* str, int64_t k) {
        if (str) {
            assert(str->length >= k);
            if (str->substring) {
                return get_char(str->raw, str->l + k - 1);
            } else {
                if (k <= str->left->length) {
                    return get_char(str->left, k);
                } else {
                    return get_char(str->right, k - str->left->length);
                }
            }
        } else {
            return s[k];
        }
    }
};
void solve() {
    cin >> n >> c >> q >> s;
    string_t* str = string_t::get_substring(nullptr, 0, n - 1);
    int64_t l, r;
    for (int i = 1; i <= c; i++) {
        cin >> l >> r;
        str = string_t::combine(str, string_t::get_substring(str, l, r));
    }
    int64_t k;
    for (int i = 1; i <= q; i++) {
        cin >> k;
        cout << string_t::get_char(str, k) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}