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
#include <unordered_set>

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

using Piv = pair<int, vector<int>>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> c(n);
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        a[i].resize(c[i]);
        for(int j = 0; j < c[i]; j++) cin >> a[i][j];
    }
    set<vector<int>> banned;
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            v[i]--;
        }
        banned.insert(v);
    }
    priority_queue<Piv> que;
    set<vector<int>> used;
    auto calc_sum = [&](vector<int> &v){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i][v[i]];
        }
        return sum;
    };
    auto push = [&](vector<int> &v){
        if(used.count(v)) return;
        int sum = calc_sum(v);
        que.push(Piv(sum, v));
        used.insert(v);
    };
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = c[i]-1;
    push(v);
    while(true){
        auto [_, v] = que.top(); que.pop();
        if(banned.count(v) == 0){
            for(int x: v) cout << x+1 << ' ';
            cout << endl;
            return 0;
        }
        for(int i = 0; i < n; i++){
            if(v[i] != 0){
                v[i]--;
                push(v);
                v[i]++;
            }
        }
    }
}