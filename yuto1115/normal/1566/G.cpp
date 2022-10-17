#include<bits/stdc++.h>
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(i, n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i, s, n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i, s, n, d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(i, n) for (ll i = ll(n)-1; i >= 0; i--)
#define rrep2(i, n, t) for (ll i = ll(n)-1; i >= (ll)t; i--)
#define rrep3(i, n, t, d) for (ll i = ll(n)-1; i >= (ll)t; i-=d)
#define rrep(...) overload4(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define SUM(a) accumulate(all(a),0LL)
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SZ(a) int(a.size())
#define popcount(x) __builtin_popcountll(x)
#define pf push_front
#define pb push_back
#define ef emplace_front
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
#ifdef __LOCAL
#define debug(...) { cout << #__VA_ARGS__; cout << ": "; print(__VA_ARGS__); cout << flush; }
#else
#define debug(...) void(0);
#endif
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vp = vector<P>;
using vvp = vector<vp>;

template<class S, class T>
istream &operator>>(istream &is, pair<S, T> &p) { return is >> p.first >> p.second; }

template<class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << '{' << p.first << ", " << p.second << '}'; }

template<class S, class T, class U>
istream &operator>>(istream &is, tuple<S, T, U> &t) { return is >> get<0>(t) >> get<1>(t) >> get<2>(t); }

template<class S, class T, class U>
ostream &operator<<(ostream &os, const tuple<S, T, U> &t) {
    return os << '{' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << '}';
}

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &t : v) { is >> t; }
    return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '[';
    rep(i, v.size()) os << v[i] << (i == int(v.size() - 1) ? "" : ", ");
    return os << ']';
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &st) {
    os << '{';
    auto it = st.begin();
    while (it != st.end()) {
        os << (it == st.begin() ? "" : ", ") << *it;
        it++;
    }
    return os << '}';
}

template<class T>
void vecout(const vector<T> &v, char div = '\n') {
    rep(i, v.size()) cout << v[i] << (i == int(v.size() - 1) ? '\n' : div);
}

template<class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void scan() {}

template<class Head, class... Tail>
void scan(Head &head, Tail &... tail) {
    cin >> head;
    scan(tail...);
}

template<class T>
void print(const T &t) { cout << t << '\n'; }

template<class Head, class... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

template<class... T>
void fin(const T &... a) {
    print(a...);
    exit(0);
}

struct Init_io {
    Init_io() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout << boolalpha << fixed << setprecision(15);
        cerr << boolalpha << fixed << setprecision(15);
    }
} init_io;

const string yes[] = {"no", "yes"};
const string Yes[] = {"No", "Yes"};
const string YES[] = {"NO", "YES"};
const int inf = 1001001001;
const ll linf = 1001001001001001001;

template<class T, class S>
vector<T> cumsum(const vector<S> &v, bool shift_one = true) {
    int n = v.size();
    vector<T> res;
    if (shift_one) {
        res.resize(n + 1);
        rep(i, n) res[i + 1] = res[i] + v[i];
    } else {
        res.resize(n);
        if (n) {
            res[0] = v[0];
            rep(i, 1, n) res[i] = res[i - 1] + v[i];
        }
    }
    return res;
}

vvi graph(int n, int m, bool directed = false, int origin = 1) {
    vvi G(n);
    rep(_, m) {
        INT(u, v);
        u -= origin, v -= origin;
        G[u].pb(v);
        if (!directed) G[v].pb(u);
    }
    return G;
}

template<class T>
vector<vector<pair<int, T>>> weighted_graph(int n, int m, bool directed = false, int origin = 1) {
    vector<vector<pair<int, T>>> G(n);
    rep(_, m) {
        int u, v;
        T w;
        scan(u, v, w);
        u -= origin, v -= origin;
        G[u].eb(v, w);
        if (!directed) G[v].eb(u, w);
    }
    return G;
}

int main() {
    INT(n, m);
    vi u(m), v(m), w(m);
    map<P, int> mp;
    vector<set<P>> G(n);
    set<P> es;
    vi used(m, 2);
    rep(i, m) {
        scan(u[i], v[i], w[i]);
        --u[i], --v[i];
        if (u[i] > v[i]) swap(u[i], v[i]);
        mp[{u[i], v[i]}] = i;
        G[u[i]].insert({w[i], i});
        G[v[i]].insert({w[i], i});
        es.insert({w[i], i});
    }
    multiset<ll> ver;
    auto add = [&](int i) {
        if (G[i].size() < 3) return;
        ll tmp = 0;
        auto it = G[i].begin();
        rep(j, 3) {
            if (j) ++it;
            tmp += it->first;
        }
        ver.insert(tmp);
    };
    auto del = [&](int i) {
        if (G[i].size() < 3) return;
        ll tmp = 0;
        auto it = G[i].begin();
        rep(j, 3) {
            if (j) ++it;
            tmp += it->first;
        }
        ver.erase(ver.find(tmp));
    };
    rep(i, n) {
        add(i);
        if (G[i].size() > 3) {
            auto it = next(G[i].begin(), 3);
            while (it != G[i].end()) {
                if (--used[it->second] == 1) {
                    es.erase(*it);
                }
                ++it;
            }
        }
    }
    auto solve = [&] {
        ll ans = linf;
        if (ver.size()) chmin(ans, *ver.begin());
        {
            auto[w1, id1] = *es.begin();
            auto it = next(es.begin());
            while (it != es.end()) {
                auto[w2, id2] = *it;
                if (u[id1] == u[id2] or u[id1] == v[id2] or v[id1] == u[id2] or v[id1] == v[id2]) {
                    ++it;
                    continue;
                }
                chmin<ll>(ans, w1 + w2);
                break;
            }
        }
        {
            int mn_id = es.begin()->second;
            int c1 = 0;
            for (auto[w1, id1] : G[u[mn_id]]) {
                if (++c1 > 3) break;
                int c2 = 0;
                for (auto[w2, id2] : G[v[mn_id]]) {
                    if (++c2 > 3) break;
                    if (u[id1] == u[id2] or u[id1] == v[id2] or v[id1] == u[id2] or v[id1] == v[id2]) {
                        continue;
                    }
                    chmin<ll>(ans, w1 + w2);
                }
            }
        }
        print(ans);
    };
    solve();
    INT(q);
    while (q--) {
        INT(t);
        if (t == 0) {
            INT(nu, nv);
            --nu, --nv;
            if (nu > nv) swap(nu, nv);
            int id = mp[{nu, nv}];
            bool flag_u = false;
            {
                auto it = G[nu].begin();
                rep(_,3) {
                    if(it == G[nu].end()) break;
                    if(it->second == id) flag_u = true;
                    ++it;
                }
            }
            bool flag_v = false;
            {
                auto it = G[nv].begin();
                rep(_,3) {
                    if(it == G[nv].end()) break;
                    if(it->second == id) flag_v = true;
                    ++it;
                }
            }
            del(nu), del(nv);
            G[nu].erase({w[id], id});
            G[nv].erase({w[id], id});
            add(nu), add(nv);
            if (used[id] == 2) {
                es.erase({w[id], id});
                if(flag_u and G[nu].size() >= 3) {
                    auto it = next(G[nu].begin(),2);
                    if(used[it->second]++ == 1) {
                        es.insert(*it);
                    }
                }
                if(flag_v and G[nv].size() >= 3) {
                    auto it = next(G[nv].begin(),2);
                    if(used[it->second]++ == 1) {
                        es.insert(*it);
                    }
                }
            }
        } else {
            u.pb(0), v.pb(0), w.pb(0);
            scan(u.back(), v.back(), w.back());
            --u.back(), --v.back();
            if (u.back() > v.back()) swap(u.back(), v.back());
            mp[{u.back(), v.back()}] = SZ(u) - 1;
            del(u.back()), del(v.back());
            G[u.back()].insert({w.back(), SZ(u) - 1});
            G[v.back()].insert({w.back(), SZ(u) - 1});
            add(u.back()), add(v.back());
            used.pb(0);
            {
                if(G[u.back()].size() <= 3) {
                    used.back()++;
                } else if(*next(G[u.back()].begin(),2) >= P(w.back(),SZ(u)-1)) {
                    used.back()++;
                    auto it = next(G[u.back()].begin(),3);
                    if(--used[it->second] == 1) {
                        es.erase(*it);
                    }
                }
            }
            {
                if(G[v.back()].size() <= 3) {
                    used.back()++;
                } else if(*next(G[v.back()].begin(),2) >= P(w.back(),SZ(u)-1)) {
                    used.back()++;
                    auto it = next(G[v.back()].begin(),3);
                    if(--used[it->second] == 1) {
                        es.erase(*it);
                    }
                }
            }
            if(used.back() == 2) es.insert({w.back(), SZ(u) - 1});
        }
        solve();
    }
}