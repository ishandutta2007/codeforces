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
    string t; cin >> t;
    auto ask = [&](string s){
        cout << "? " << s << endl;
        string ans; cin >> ans;
        return ans;
    };
    int n = t.size();
    int x = 1;
    vector<int> indices(n);
    vector<int> original(n);
    iota(indices.begin(), indices.end(), 0);
    for(int i = 0; i < 3; i++){
        string s;
        for(int j = 0; j < n; j++){
            s += 'a'+(indices[j]%26);
            indices[j] /= 26;
        }
        auto ans = ask(s);
        for(int j = 0; j < n; j++){
            original[j] += x*(ans[j]-'a');
        }
        x *= 26;
    }
    string ans(n, 'a');
    for(int i = 0; i < n; i++) ans[original[i]] = t[i];
    cout << "! " << ans << endl;
}