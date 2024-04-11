//@formatter:off
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define rrep(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = int(s); i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<P>
#define vvp vector<vector<P>>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
void YES(bool b) { cout << (b ? "YES" : "NO") << '\n'; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

vvp OG;

// G is the tree
// can calc diameter by "dfs(dfs(0).second).first"
P diameter(int v, int p = -1) {
    int ret = 0, ind = v;
    for (auto[u, _] : OG[v]) {
        if (u == p) continue;
        auto d = diameter(u, v);
        if (chmax(ret, d.first + 1)) ind = d.second;
    }
    return {ret, ind};
}

template<class Node>
class lazy_segtree {
    using V = typename Node::value_structure;
    using VT = typename V::value_type;
    using O = typename Node::operate_structure;
    using OT = typename O::value_type;
    
    int n;
    vector<Node> tree;
    
    void propagate(int k, int l, int r) {
//        if (tree[k].op.value == O::identity) return;
        if (k < n) {
            tree[k * 2].op.value = O::operate(tree[k * 2].op.value, tree[k].op.value);
            tree[k * 2 + 1].op = O::operate(tree[k * 2 + 1].op.value, tree[k].op.value);
        }
        OT ot = O::duplicate(tree[k].op.value, r - l);
        tree[k].value.value = Node::operate(tree[k].value.value, ot);
        tree[k].op.value = O::identity;
    }

public:
    VT get(int i) { return Node::operate(tree[i].value.value, tree[i].op.value); }
    
    lazy_segtree(int _n, vector<VT> init = vector<VT>()) {
        n = 1;
        while (n < _n) n *= 2;
        tree.assign(n * 2, Node{V::identity, O::identity});
        if (init.size()) rep(i, _n) tree[i + n].value.value = init[i];
        rrep(i, n) tree[i].value.value = V::operate(tree[i * 2].value.value, tree[i * 2 + 1].value.value);
    }
    
    void update(int a, int b, OT x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        propagate(k, l, r);
        if (a <= l && r <= b) {
            tree[k].op.value = O::operate(tree[k].op.value, x);
            propagate(k, l, r);
        } else if (a < r && l < b) {
            update(a, b, x, k * 2, l, (l + r) / 2);
            update(a, b, x, k * 2 + 1, (l + r) / 2, r);
            tree[k].value.value = V::operate(tree[k * 2].value.value, tree[k * 2 + 1].value.value);
        }
    }
    
    // segment [a,b)
    VT fold(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        propagate(k, l, r);
        if (b <= l || r <= a) return V::identity;
        if (a <= l && r <= b) return tree[k].value.value;
        VT lt = fold(a, b, k * 2, l, (l + r) / 2);
        VT rt = fold(a, b, k * 2 + 1, (l + r) / 2, r);
        return V::operate(lt, rt);
    }
};

class Value_structure {
public:
    using value_type = P;
    
    value_type value;
    
    Value_structure(value_type value) : value(value) {}
    
    static constexpr value_type identity = {-1, -1};
    
    static constexpr value_type operate(const value_type &l, const value_type &r) {
        return {max(l.first, r.first), max(l.second, r.second)};
    }
};

class Operate_structure {
public:
    using value_type = int;
    
    value_type value;
    
    Operate_structure(value_type value) : value(value) {}
    
    static constexpr value_type identity = 0;
    
    static constexpr value_type operate(const value_type &l, const value_type &r) {
        return l ^ r;
    }
    
    static constexpr value_type duplicate(const value_type &v, int len) {
        return v;
    }
};

class Node {
public:
    using value_structure = Value_structure;
    using operate_structure = Operate_structure;
    
    value_structure value;
    operate_structure op;

private:
    using V = value_structure::value_type;
    using O = operate_structure::value_type;

public:
    Node(V value, O op) : value(value), op(op) {}
    
    static constexpr V operate(const V &l, const O &r) {
        if (r == 0) return l;
        else return {l.second, l.first};
    }
};


class Graph {
    struct edge {
        int u, v, u_id, v_id;
        
        void swap() {
            ::swap(u, v);
            ::swap(u_id, v_id);
        }
    };
    
    int root;
    int n;
    vvp G;
    vector<edge> ls;
    vi depth;
    vp euler;
    vi in, out;
    lazy_segtree<Node> st;
    
    void dfs(int v, int p, int d, int x) {
        depth[v] = d;
        in[v] = euler.size();
        euler.eb(d, x);
        for (auto[u, t] : G[v]) {
            if (u == p) continue;
            dfs(u, v, d + 1, x ^ t);
        }
        out[v] = euler.size();
    }
    
    void init() {
        depth.resize(n);
        in.resize(n);
        out.resize(n);
        dfs(root, -1, 0, 0);
        for (edge &e : ls) {
            if (depth[e.u] > depth[e.v]) e.swap();
        }
        vp v;
        rep(i, n) {
            auto[f, s] = euler[i];
            if (s == 0) v.eb(f, -1);
            else v.eb(-1, f);
        }
        st = lazy_segtree<Node>(n, v);
    }

public:
    Graph(int root, int n, vector<tuple<int, int, int>> &es) : root(root), n(n), st(n) {
        G.resize(n);
        for (auto[u, v, t] : es) {
            ls.pb(edge{u, v, (int) G[u].size(), (int) G[v].size()});
            G[u].eb(v, t);
            G[v].eb(u, t);
        }
        init();
    }
    
    int query(int x) {
        int now = ls[x].v;
        st.update(in[now], out[now], 1);
        return st.fold(0, n).first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    OG.resize(n);
    vector<tuple<int, int, int>> es;
    rep(_, n - 1) {
        int u, v, t;
        cin >> u >> v >> t;
        u--;
        v--;
        OG[u].eb(v, t);
        OG[v].eb(u, t);
        es.eb(u, v, t);
    }
    int a = diameter(0).second;
    int b = diameter(a).second;
    Graph ga(a, n, es);
    Graph gb(b, n, es);
    int m;
    cin >> m;
    while (m--) {
        int id;
        cin >> id;
        id--;
        int ma = ga.query(id);
        int mb = gb.query(id);
        cout << max(ma, mb) << '\n';
    }
}