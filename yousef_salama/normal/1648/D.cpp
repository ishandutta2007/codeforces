#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

struct segtree{
    int n;
    vector <long long> tree;

    segtree(const vector <long long>& v){
        n = v.size();
        tree.resize(2 * n);
        copy(v.begin(), v.end(), tree.begin() + n);
        
        for(int i = n - 1; i >= 1; i--)
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    void modify(int i, long long v){
        for(i += n; i >= 1; i >>= 1)
            tree[i] = max(tree[i], v);
    }

    long long find_max(int l, int r){
        long long ret = -INF;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l & 1)ret = max(ret, tree[l++]);
            if(r & 1)ret = max(ret, tree[--r]);
        }
        return ret;
    }
};

struct segtree_pairs{
    struct node{
        long long best_pair, best_a, best_b;

        node(): best_pair(-INF), best_a(-INF), best_b(-INF){}
        node(long long a, long long b): best_pair(-INF), best_a(a), best_b(b){};
        node(long long best_pair, long long a, long long b): best_pair(best_pair), best_a(a), best_b(b){};
    };
    
    node combine(const node& a, const node& b){
        return node(max({a.best_pair, b.best_pair, a.best_a + b.best_b}),
                 max(a.best_a, b.best_a), max(a.best_b, b.best_b));
    }

    int n;
    vector <node> tree;

    segtree_pairs(const vector <long long>& v, const vector <long long>& w){
        assert(v.size() == w.size());

        n = v.size();
        tree.resize(2 * n);

        for(int i = 2 * n - 1; i >= n; i--)
            tree[i] = node(v[i - n], w[i - n]);
        for(int i = n - 1; i >= 1; i--)
            tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
    }

    long long find_max(int l, int r){
        node p_left, p_right;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l & 1)p_left = combine(p_left, tree[l++]);
            if(r & 1)p_right = combine(tree[--r], p_right);
        }
        return combine(p_left, p_right).best_pair;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector a(3, vector <int> (n));
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < n; j++)
        cin >> a[i][j];

    vector < vector < pair <int, int> > > intervals(n + 1);
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        l--;

        intervals[r].push_back(make_pair(l, k));
    }

    vector sum(3, vector <long long> (n + 1));
    for(int i = 0; i < 3; i++){
        sum[i][0] = 0;
        for(int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + a[i][j - 1];
    }

    vector <long long> st(n + 1), en(n + 1);
    
    for(int i = 0; i < n; i++)
        st[i] = sum[0][i + 1] - sum[1][i];
    
    for(int i = 1; i <= n; i++)
        en[i] = sum[1][i] + sum[2][n] - sum[2][i - 1];

    segtree tree_st(st);
    vector <long long> dp(n + 1, -INF);
    
    for(int i = 1; i < n; i++){
        for(auto[l, k] : intervals[i])
            dp[i] = max(dp[i], tree_st.find_max(l, i) - k);
        tree_st.modify(i, dp[i]);
    }

    for(int i = 0; i < n; i++)
        dp[i] = max(dp[i], st[i]);

    segtree_pairs tree_pairs(dp, en);

    long long res = -INF;

    for(int i = 1; i <= n; i++)
    for(auto[l, k] : intervals[i])
        res = max(res, tree_pairs.find_max(l, i + 1) - k);

    cout << res << '\n';

    return 0;
}