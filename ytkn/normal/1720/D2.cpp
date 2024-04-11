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

struct node{
    int bit_idx;
    array<int, 2> children;
    array<int, 2> mx;
    node(int bit_idx): bit_idx(bit_idx) {
        children = {{-1, -1}};
        mx = {{0, 0}};
    };
};

/**
 * verified: https://judge.yosupo.jp/submission/73930
 */ 
template<int MAX_BIT=30>
struct BinaryTrie{
    public:
    vector<node> nodes;
    int n_nodes = 0;
    BinaryTrie() {
        nodes.push_back(node(MAX_BIT));
        n_nodes = 1;
    };

    int root(){
        return 0;
    }

    void add(int a, int i, int val){
        add(root(), a, i, val);
    }

    int get_max(int a, int i){
        return get_max(root(), a, i);
    }

    private:
    int get_max(const int idx, int a, int i){
        if(nodes[idx].bit_idx == 0) return 0;
        int v = kth_bit(a^i, nodes[idx].bit_idx-1);
        int ans = 0;
        int ch = v^1; // bit
        int ch_idx = nodes[idx].children[ch];
        if(ch_idx != -1){
            int x = kth_bit(a, nodes[idx].bit_idx-1)^1;
            chmax(ans, nodes[ch_idx].mx[x]);
        }
        if(nodes[idx].children[v] != -1) chmax(ans, get_max(nodes[idx].children[v], a, i));
        return ans;
    }

    void add(const int idx, int a, int i, int val){
        int v = kth_bit(i, nodes[idx].bit_idx);
        chmax(nodes[idx].mx[v], val);
        if(nodes[idx].bit_idx == 0) return;
        int ch = kth_bit(a^i, nodes[idx].bit_idx-1);
        if(nodes[idx].children[ch] == -1){
            nodes.push_back(node(nodes[idx].bit_idx-1));
            nodes[idx].children[ch] = n_nodes;
            n_nodes++;
        }
        assert(nodes[idx].children[ch] != -1);
        add(nodes[idx].children[ch], a, i, val);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n);
    auto trie = BinaryTrie<30>();
    for(int i = 0; i < n; i++){
        dp[i] = trie.get_max(a[i], i)+1;
        trie.add(a[i], i, dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}