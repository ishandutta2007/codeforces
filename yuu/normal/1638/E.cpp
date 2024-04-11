#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
  public:
    using pointer = SegmentTree*;
    int color;
};

class Segment {
  public:
    int l, r, c;

    bool operator<(const Segment& s) const {
        if (l != s.l)
            return l < s.l;
        else if (r != s.r)
            return r < s.r;
        else
            return c < s.c;
    }
};
class DisjointSegmentSet : set<Segment> {
  public:
    void Add(const Segment& s, vector<Segment>& pop) {
        while (true) {
            if (empty() || (s.l > rbegin()->r) || (s.r < begin()->l)) {
                insert(s);
                return;
            }
            if (rbegin()->l <= s.l) {
                auto left = *rbegin();
                erase(left);
                if (left.r > s.r) {
                    if (left.l < s.l) {
                        insert({left.l, s.l - 1, left.c});
                        insert({s.r + 1, left.r, left.c});
                        pop.push_back({s.l, s.r, left.c});
                    } else {
                        insert({s.r + 1, left.r, left.c});
                        pop.push_back({left.l, s.r, left.c});
                    }
                } else if (left.l < s.l) {
                    insert({left.l, s.l - 1, left.c});
                    assert(s.l <= left.r);
                    pop.push_back({s.l, left.r, left.c});
                } else {
                    assert(left.l == s.l);
                    pop.push_back(left);
                }
                insert(s);
                return;
            } else {
                auto it = upper_bound(s);
                assert(it->l >= s.l);
                if (it->l <= s.r) {
                    auto right = (*it);
                    erase(it);
                    if (right.r > s.r) {
                        insert({s.r + 1, right.r, right.c});
                        pop.push_back({right.l, s.r, right.c});
                    } else {
                        pop.push_back(right);
                    }
                } else {
                    it = prev(it);
                    assert(it->l <= s.l);
                    if (it->r < s.l) {
                        insert(s);
                        return;
                    } else {
                        auto left = (*it);
                        erase(it);
                        if (left.r > s.r) {
                            if (left.l < s.l) {
                                insert({left.l, s.l - 1, left.c});
                                insert({s.r + 1, left.r, left.c});
                                pop.push_back({s.l, s.r, left.c});
                            } else {
                                assert(left.l == s.l);
                                insert({s.r + 1, left.r, left.c});
                                pop.push_back({left.l, s.r, left.c});
                            }
                        } else if (left.l < s.l) {
                            insert({left.l, s.l - 1, left.c});
                            pop.push_back({s.l, left.r, left.c});
                        } else {
                            assert(left.l == s.l);
                            pop.push_back(left);
                        }
                        insert(s);
                        return;
                    }
                }
            }
        }
    }

    int GetColor(int pos) {
        assert(!empty());
        if (pos >= rbegin()->l) return rbegin()->c;
        auto it = prev(upper_bound({pos, 10000000, 10000000}));
        assert(it != end());
        assert((it->l <= pos) && (it->r >= pos));
        return it->c;
    }

    friend ostream& operator<<(ostream& val, const DisjointSegmentSet& dss) {
        val << "{\n";
        for (auto&& [l, r, c] : dss) {
            val << l << ' ' << r << ' ' << c << '\n';
        }
        return val << "}\n";
    }
};

int n, q;
DisjointSegmentSet dss;
int64_t ft[1000001];
void update(int u, int64_t x) {
    for (; u <= n; u += (u & -u)) ft[u] += x;
}
int64_t get(int u) {
    int64_t res = 0;
    for (; u > 0; u -= (u & -u)) res += ft[u];
    return res;
}

int64_t sum[1000001];
vector<Segment> pop;
void solve() {
    cin >> n >> q;
    string s;
    int l, r, c;
    dss.Add({1, n, 1}, pop);
    for (int i = 1; i <= q; i++) {
        cin >> s >> l;
        if (s[0] == 'C') {
            cin >> r >> c;
            pop.clear();
            dss.Add({l, r, c}, pop);
            for (auto&& [x, y, p] : pop) {
                // cerr << "Pop: " << x << ' ' << y << ' ' << p << '\n';
                update(x, sum[p]);
                update(y + 1, -sum[p]);
            }
            update(l, -sum[c]);
            update(r + 1, sum[c]);
        } else if (s[0] == 'A') {
            cin >> r;
            sum[l] += r;
        } else {
            cout << get(l) + sum[dss.GetColor(l)] << '\n';
            // cerr << "Query: " << l << ' ' << get(l) << ' ' << dss.GetColor(l) << ' ' << sum[dss.GetColor(l)] << '\n';
        }
        // cerr << dss << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}