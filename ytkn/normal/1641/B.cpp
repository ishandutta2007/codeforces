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
    cout << v.back() << '\n';
}

using P = pair<int, int>;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    map<int, vector<int>> indices;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> used, rem;
    vector<int> sections;
    vector<P> insertions;
    for(int x: a) rem.push_back(x);
    while(rem.size() > 0){
        int m = rem.size();
        vector<int> v;
        auto nx = [&](){
            for(int i = 1; i < m; i++){
                if(rem[i] == rem[0]){
                    return i;
                }
                v.push_back(rem[i]);
            }
            return -1;
        }();
        if(nx == -1){
            cout << -1 << '\n';
            return;
        }
        for(int i = 0; i <= nx; i++){
            used.push_back(rem.front());
            rem.pop_front();
        }
        sections.push_back(nx*2);
        for(int x: v){
            insertions.push_back(P(used.size(), x));
            used.push_back(x);
            rem.push_front(x);
        }
    }
    cout << insertions.size() << '\n';
    for(auto [idx, x]: insertions) cout << idx << ' ' << x << '\n';
    cout << sections.size() << '\n';
    print_vector(sections);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}