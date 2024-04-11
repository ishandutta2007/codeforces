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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    auto a = vec2d(n, m, 0);
    auto b = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    vector<bool> same(n-1, true);
    vector<int> rem(m);
    queue<int> que;
    vector<int> ans;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n-1; i++){
            if(b[i][j] > b[i+1][j]) rem[j]++;
        }
        if(rem[j] == 0) que.push(j);
    }
    while(!que.empty()){
        int j = que.front(); que.pop();
        ans.push_back(j);
        vector<int> v;
        for(int i = 0; i < n-1; i++){
            if(same[i] && b[i][j] != b[i+1][j]){
                same[i] = false;
                v.push_back(i);
            }
        }
        for(int i: v){
            for(int j = 0; j < m; j++){
                if(b[i][j] > b[i+1][j]) {
                    rem[j]--;
                    if(rem[j] == 0) que.push(j);
                }
            }
        }
    }
    auto rev_ans = ans;
    reverse(ans.begin(), ans.end());
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    auto comp = [&](int i1, int i2){
        for(int j: rev_ans){
            if(a[i1][j] != a[i2][j]) return a[i1][j] < a[i2][j];
        }
        return i1 < i2;
    };
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < n; i++){
        int idx = v[i];
        if(a[idx] != b[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans.size() << endl;
    for(int j: ans) cout << j+1 << ' ';
    cout << endl;
}