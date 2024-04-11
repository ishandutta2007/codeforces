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
    int n; cin >> n;
    string s; cin >> s;
    int cnt_w = 0, cnt_b = 0;
    for(char c: s){
        if(c == 'W') cnt_w++;
        else cnt_b++;
    }
    if(n%2 == 0 && cnt_b%2 == 1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    auto invert = [&](int i){
        if(s[i] == 'W') s[i] = 'B';
        else s[i] = 'W';
    };
    for(int i = 1; i < n-1; i++){
        if(s[i] != s[i-1]){
            invert(i);
            invert(i+1);
            ans.push_back(i);
        }
    }
    if(s[0] != s[n-1]){
        for(int i = 0; i < n-1; i+=2){
            invert(i);
            invert(i+1);
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i: ans) cout << i+1 << ' ';
    cout << endl;
}