#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

class Trie{
    struct node{
        char val;
        int depth;
        bool is_end;
        vector<int> children;
        ll sum;
        node(char val, int depth): val(val), depth(depth) {
            children = vector<int>();
            is_end = false;
            sum = 0;
        };
    };
    public:
    vector<node> nodes;
    int n_nodes = 0;
    int n_bits;
    Trie() {
        nodes.push_back(node('#', 0));
        n_nodes = 1;
    };

    int get_child(int nd_idx, char c){
        for(int i: nodes[nd_idx].children){
            if(nodes[i].val == c) return i;
        }
        assert(false);
    }

    int root(){
        return 0;
    }

    bool has_child(int nd_idx, char c){
        for(int i: nodes[nd_idx].children){
            if(nodes[i].val == c) return true;
        }
        return false;
    }

    void add(string &s, ll score){
        add(root(), s, score);
    }

    void dfs(ll &g){
        for(int i: nodes[root()].children) dfs(nodes[i], g);
    }

    private:
    void add(int nd_idx, string &s, ll score){
        int depth = nodes[nd_idx].depth;
        if(depth == s.size()) {
            nodes[nd_idx].is_end = true;
            nodes[nd_idx].sum += score;
            return;
        }
        if(!has_child(nd_idx, s[depth])){
            nodes.push_back(node(s[depth], depth+1));
            nodes[nd_idx].children.push_back(n_nodes);
            n_nodes++;
        }
        add(get_child(nd_idx, s[depth]), s, score);
    }

    void dfs(node &nd, ll &g){
        if(nd.is_end){
            g = gcd(g, nd.sum);
        }
        for(int i: nd.children) dfs(nodes[i], g);
    }
};

using Psi = pair<string, int>;
string pad[500000];

void init(){
    for(int i = 0; i < 500000; i++){
        string s = to_string(i);
        while(s.size() <= 5) s = "0"+s;
        pad[i] = s;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> indices(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        indices[v].push_back(u);
    }
    auto trie = Trie();
    for(int i = 0; i < n; i++){
        sort(indices[i].begin(), indices[i].end());
        string s;
        for(int idx: indices[i]) s += pad[idx];
        trie.add(s, c[i]);
        // cout << s << endl;
    }
    ll ans = 0;
    trie.dfs(ans);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--) solve();
}