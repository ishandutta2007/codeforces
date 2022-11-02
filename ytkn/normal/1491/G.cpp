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
#include <random>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

vector<int> gen_permutation(int n) {
    random_device seed_gen;
    mt19937 engine(seed_gen());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = i;
    shuffle(ans.begin(), ans.end(), engine);
    return ans;
}

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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i]; c[i]--;
    }
    vector<bool> flipped(n);
    UnionFind uf(n);
    for(int i = 0; i < n; i++){
        uf.unionSet(i, c[i]);
    }
    vector<vector<int>> components(n);
    for(int i = 0; i < n; i++){
        components[uf.root(i)].push_back(i);
    }
    vector<P> ans;
    auto add = [&](int i, int j){
        swap(c[i], c[j]);
        bool fi = !flipped[j];
        bool fj = !flipped[i];
        flipped[i] = fi;
        flipped[j] = fj;
        ans.push_back(P(i, j));
    };
    vector<int> roots;
    for(int i = 0; i < n; i++){
        if(components[i].size() >= 2) roots.push_back(i);
    }
    for(int i = 0; i+1 < roots.size(); i+=2){
        int j1 = components[roots[i]][0];
        int j2 = components[roots[i+1]][0];
        add(j1, j2);
        uf.unionSet(j1, j2);
    }
    for(int i = 0; i < n; i++) components[i].clear();
    for(int i = 0; i < n; i++){
        int r = uf.root(i);
        components[r].push_back(i);
    }
    auto resolve_flipped_cycle = [&](int r){
        int s = r;
        while(!flipped[s]){
            s = c[s];
        }
        while(!flipped[c[s]]){
            add(s, c[s]);
        }
        s = c[s];
        while(c[s] != s){
            add(s, c[s]);
        }
    };
    auto resolve_cycle = [&](int r){
        int cnt_flipped = 0;
        for(int i: components[r]){
            if(flipped[i]) cnt_flipped++;
        }
        if(cnt_flipped == 2){
            resolve_flipped_cycle(r);
            return;
        }
        assert(cnt_flipped == 0);
        int s = components[r][0];
        vector<int> v = {s};
        int cur = s;
        while(true){
            cur = c[cur];
            if(cur == s) break;
            v.push_back(cur);
        }
        if(components[r].size() == 2){
            int extra = -1;
            for(int i = 0; i < n; i++){
                if(i != v[0] && i != v[1]){
                    extra = i;
                    break;
                }
            }
            add(v[0], extra);
            add(v[1], extra);
            add(v[0], extra);
        }else{
            int s = components[r][0];
            int t = c[s];
            int u = c[t];
            add(s, t);
            add(t, u);
            resolve_flipped_cycle(r);
        }
    };
    for(int i = 0; i < n; i++){
        if(components[i].size() <= 1) continue;
        resolve_cycle(i);
    }
    cout << ans.size() << endl;
    for(auto [i, j]: ans) cout << i+1 << ' ' << j+1 << '\n';
}