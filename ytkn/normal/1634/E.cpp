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

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int m; cin >> m;
    vector<int> v;
    vector<vector<int>> a(m);
    for(int i = 0; i < m; i++){
        int n; cin >> n;
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            a[i].push_back(x);
            v.push_back(x);
        }
    }
    auto cp = Compress<int>(v);
    int n = cp.size();
    vector<vector<P>> indices(n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < a[i].size(); j++){
            int x = cp[a[i][j]];
            indices[x].push_back(P(i, j));
        }
    }
    for(int i = 0; i < n; i++){
        if(indices[i].size()%2 != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    vector<string> ans(m);
    vector<vector<P>> g(m);
    vector<set<int>> rem(m);
    for(int i = 0; i < m; i++){
        ans[i] = string(a[i].size(), 'L');
        g[i].resize(a[i].size());
        for(int j = 0; j < a[i].size(); j++) rem[i].insert(j);
    }
    auto add_edge = [&](int i1, int j1, int i2, int j2){
        // cout << i1 << ' ' << j1 << ":" << i2 << ' ' << j2 << endl;
        g[i1][j1] = P(i2, j2);
        g[i2][j2] = P(i1, j1);
    };
    auto erase_edge = [&](int i1, int j1, int i2, int j2){
        rem[i1].erase(j1);
        rem[i2].erase(j2);
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < indices[i].size(); j+=2){
            auto [i1, j1] = indices[i][j];
            auto [i2, j2] = indices[i][j+1];
            if(i1 == i2){
                ans[i1][j1] = 'L';
                ans[i1][j2] = 'R';
                rem[i1].erase(j1);
                rem[i1].erase(j2);
            }else{
                add_edge(i1, j1, i2, j2);
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < a[i].size(); j++){
            if(rem[i].count(j) == 0) continue;
            P cur = P(i, j);
            // cout << i << ' ' << j << endl;
            while(true){
                auto [i1, j1] = cur;
                P nx = g[i1][j1];
                auto [i2, j2] = nx;
                // cout << i1 << ' ' << j1 << "->" << i2 << ' ' << j2 << endl;
                erase_edge(i1, j1, i2, j2);
                ans[i1][j1] = 'L';
                ans[i2][j2] = 'R';
                if(rem[i2].empty()) break;
                int j3 = *rem[i2].begin();
                cur = P(i2, j3);
            }
            // cout << "====" << endl;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
}