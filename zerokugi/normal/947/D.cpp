#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i, x) for(int i=0;i<(int)(x);i++)
#define REPS(i, x) for(int i=1;i<=(int)(x);i++)
#define RREP(i, x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i, x) for(int i=((int)(x));i>0;i--)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i, c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define __builtin_popcount __builtin_popcountll

const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;

struct handler {
    typedef pii val_t; // (num of B, rightest B)
    handler() {}

    val_t def_val() { return pii(-1, -1); }

    static val_t merge(const val_t &l, const val_t &r) {
        if (l.first == -1) return r;
        if (r.first == -1) return l;
        return pii(l.first + r.first, max(r.second, l.second));
    }
};

template<typename Handler>
struct SegTree {
    typedef typename Handler::val_t val_t;
    vector<val_t> val;
    Handler hdl;
    int n;

    SegTree(int size = 0) : hdl() {
        n = 1;
        while (n < size) n <<= 1;
        val = vector<val_t>(2 * n, hdl.def_val());
    }

    SegTree(const vector<val_t> &in) : hdl() {
        n = 1;
        while (n < in.size()) n <<= 1;
        val = vector<val_t>(2 * n, hdl.def_val());
        for (int i = n - 1 + in.size() - 1; i >= 0; i--) {
            if (n - 1 <= i) val[i] = in[i - (n - 1)];
            else val[i] = hdl.merge(val[i * 2 + 1], val[i * 2 + 2]);
        }
    }

    val_t query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return hdl.def_val();
        if (a <= l && r <= b) return val[k];
        return hdl.merge(query(a, b, k * 2 + 1, l, (l + r) / 2),
                         query(a, b, k * 2 + 2, (l + r) / 2, r)
        );
    }

    val_t query(int a, int b) { return query(a, b, 0, 0, n); }

    val_t operator[](size_t i) { return query(i, i + 1); }

    friend ostream &operator<<(ostream &os, SegTree<Handler> &t) {
        REP(i, t.n) os << (i ? ", " : "[") << "(" << t.query(i, i + 1).first << ", " << t.query(i, i + 1).second << ")";
        return os << "]";
    }
};


int n, m, x, y;
string s, t;
SegTree<handler> s1, s2;

int check(int a, int b, int c, int d) {
    auto res1 = s1.query(a, b);
    auto res2 = s2.query(c, d);
    int numB1 = res1.first;
    int numB2 = res2.first;
    int suffixA1 = res1.second == -1 ? b - a : b - res1.second - 1;
    int suffixA2 = res2.second == -1 ? d - c : d - res2.second - 1;
    if (numB1 > numB2 || suffixA1 < suffixA2) {
            return 0;
    } else if (numB1 == numB2) {
        if (suffixA1 < suffixA2 || suffixA1 % 3 != suffixA2 % 3) {
            return 0;
        }
        return 1;
    } else {
        if (numB1 % 2 != numB2 % 2) return 0;
        if (numB1 == 0 && suffixA1 - 1 < suffixA2) {
            return 0;
        }
    }
    return 1;
}

SegTree<handler> makeseg(string s) {
    int n = s.size();
    vector<pii> v;
    REP(i, n) {
        v.emplace_back(s[i] != 'A', s[i] != 'A' ? i : -1);
    }
    return SegTree<handler>(v);
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin >> s >> t >> m;
    s1 = makeseg(s);
    s2 = makeseg(t);
    REP(i, m) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
//        cout << s.substr(a, b - a) << " -> " << t.substr(c, d - c) << endl;
        cout << check(a, b, c, d);
    }
    cout << endl;
    return 0;
}