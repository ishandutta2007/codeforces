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

vector<int> get_and_compress(int n){
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto cp = Compress<int>(a);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        b[i] = cp[a[i]];
    }
    return b;
}

const int inf = 1e9;

void solve(){
    int n; cin >> n;
    auto a = get_and_compress(n);
    int m = *max_element(a.begin(), a.end())+1;
    vector<vector<int>> indices(m);
    for(int i = 0; i < n; i++){
        indices[a[i]].push_back(i);
    }
    auto dp = vec2d(n, 3, 0);
    for(int i = 0; i < m; i++) {
        for(int x: indices[i]) dp[x][0] = 1;
    }
    // print_vector(a);
    for(int i = 0; i < n; i++){
        int x = a[i];
        if(indices[x].back() != i){
            int nx = *upper_bound(indices[x].begin(), indices[x].end(), i);
            for(int j = 0; j < 3; j++) chmax(dp[nx][j], dp[i][j]+1);
        }
        if(x != m-1){
            if(indices[x+1][0] > i){ // 0 -> 1
                int nx = indices[x+1][0];
                chmax(dp[nx][1], dp[i][0]+1);
            }
            if(indices[x+1][0] > i && indices[x].back() == i){ // 1 -> 1
                int nx = indices[x+1][0];
                chmax(dp[nx][1], dp[i][1]+1);
            }
            { // 0 -> 2
                auto p = upper_bound(indices[x+1].begin(), indices[x+1].end(), i);
                if(p != indices[x+1].end()){
                    int nx = *p;
                    chmax(dp[nx][2], dp[i][0]+1);
                }
            }
            if(i == indices[x].back()){ // 1 -> 2
                auto p = upper_bound(indices[x+1].begin(), indices[x+1].end(), i);
                if(p != indices[x+1].end()){
                    int nx = *p;
                    chmax(dp[nx][2], dp[i][1]+1);
                }
            }
        }
    }
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            chmax(mx, dp[i][j]);
        }
    }
    // for(int j = 0; j < 3; j++) {
    //     for(int i = 0; i < n; i++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << n-mx << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}