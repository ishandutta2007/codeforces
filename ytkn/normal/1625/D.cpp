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



inline int kth_bit(long long x, int k){
    return (x&(1ll<<k)) ? 1 : 0;
}

inline int kth_bit(int x, int k){
    return (x&(1<<k)) ? 1 : 0;
}

template<typename T, int MAX_BIT=30>
struct BinaryTrie{
    struct node{
        int cnt, bit_idx;
        array<int, 2> children;
        node(int cnt, int bit_idx): cnt(cnt), bit_idx(bit_idx) {
            children[0] = -1;
            children[1] = -1;
        };
    };

    public:
    vector<node> nodes;
    int n_nodes = 0;
    BinaryTrie() {
        nodes.push_back(node(0, MAX_BIT));
        n_nodes = 1;
    };

    BinaryTrie(vector<int> v) {
        nodes.push_back(node(0, MAX_BIT));
        n_nodes = 1;
        for(int x: v) add(x);
    };

    int root(){
        return 0;
    }

    void add(T x){
        add(root(), x);
    }

    /**
     * x
     */ 
    int erase(T x){
        return erase(root(), x);
    }

    T max_xor(T x){
        assert(nodes[root()].cnt > 0);
        return max_xor(nodes[root()], x);
    }

    T min_xor(T x){
        assert(nodes[root()].cnt > 0);
        return min_xor(nodes[root()], x);
    }

    private:
    int erase(const int idx, T x){
        if(nodes[idx].cnt == 0) return 0;
        if(nodes[idx].bit_idx == 0) {
            int ret = nodes[idx].cnt;
            nodes[idx].cnt = 0;
            return ret;
        }
        int v = kth_bit(x, nodes[idx].bit_idx-1);
        if(nodes[idx].children[v] == -1) return 0;
        int ret = erase(nodes[idx].children[v], x);
        nodes[idx].cnt -= ret;
        return ret;
    }

    void add(const int idx, T x){
        nodes[idx].cnt++;
        if(nodes[idx].bit_idx == 0) return;
        int v = kth_bit(x, nodes[idx].bit_idx-1);
        if(nodes[idx].children[v] == -1){
            nodes.push_back(node(0, nodes[idx].bit_idx-1));
            nodes[idx].children[v] = n_nodes;
            n_nodes++;
        }
        assert(nodes[idx].children[v] != -1);
        add(nodes[idx].children[v], x);
    }

    T max_xor(const node &nd, T x){
        assert(nd.cnt > 0);
        if(nd.bit_idx == 0) return T(0);
        int v = kth_bit(x, nd.bit_idx-1);
        if(nd.children[v^1] != -1 && nodes[nd.children[v^1]].cnt > 0){
            return max_xor(nodes[nd.children[v^1]], x) + (T(1) << (nd.bit_idx-1));
        }else{
            return max_xor(nodes[nd.children[v]], x);
        }
    }

    T min_xor(const node &nd, T x){
        assert(nd.cnt > 0);
        if(nd.bit_idx == 0) return T(0);
        int v = kth_bit(x, nd.bit_idx-1);
        if(nd.children[v] != -1 && nodes[nd.children[v]].cnt > 0){
            return min_xor(nodes[nd.children[v]], x);
        }else{
            return min_xor(nodes[nd.children[v^1]], x) + (T(1) << (nd.bit_idx-1));
        }
    }

};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(k == 0){
        cout << n << endl;
        vector<int> ans;
        for(int i = 0; i < n; i++) ans.push_back(i+1);
        print_vector(ans);
        return 0;
    }
    int msb = 0;
    for(int i = 0; i <= 30; i++){
        if(k&(1<<i)) msb = i;
    }
    int prefix_mask = 0;
    for(int i = msb+1; i <= 30; i++) prefix_mask += 1<<i;
    map<int, vector<int>> mp;
    map<int, int> indices;
    for(int i = 0; i < n; i++){
        indices[a[i]] = i;
        int prefix = a[i]&prefix_mask;
        mp[prefix].push_back(a[i]);
    }
    auto to_str = [&](int x){
        string ans;
        for(int i = 30; i >= 0; i--) {
            if(x&(1<<i)) ans += '1';
            else ans += '0';
        }
        return ans;
    };
    auto list_ok = [&](int prefix) -> vector<int>{
        auto &u = mp[prefix];
        auto trie = BinaryTrie<int, 30>(u);
        for(int x: u){
            int xo = trie.max_xor(x);
            if(xo >= k) return {x, x^xo};
        }
        return {u[0]};
    };
    vector<int> ans;
    for(auto [prefix, _]: mp){
        auto v = list_ok(prefix);
        for(int x: v) ans.push_back(indices[x]+1);
    }
    if(ans.size() <= 1){
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    print_vector(ans);
}