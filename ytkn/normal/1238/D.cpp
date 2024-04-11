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

ll tri(ll x){
    return (x*(x+1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    string s; cin >> s;
    ll ans = tri(n);
    vector<vector<int>> indices(2);
    for(int i = 0; i < n; i++){
        indices[s[i]-'A'].push_back(i);
    }
    for(int i = 0; i < 2; i++) {
        indices[i].push_back(n);
        reverse(indices[i].begin(), indices[i].end());
    }
    for(int i = 0; i < n; i++){
        int c = s[i]-'A';
        while(indices[c].back() <= i){
            indices[c].pop_back();
        }
        ans -= indices[c].back()-i;
        if(i+1 < n && s[i] == s[i+1]){
            if(indices[c^1].back() != n) ans--;
        }
    }
    cout << ans << endl;
}