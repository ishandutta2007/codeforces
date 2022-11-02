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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> v;
    int sum = 0;
    while(true){
        vector<int> u;
        for(int i = 0; i+1 < n; i++){
            if(s[i] == 'R' && s[i+1] == 'L'){
                u.push_back(i);
            }
        }
        if(u.empty()){
            break;
        }
        for(int i: u) swap(s[i], s[i+1]);
        sum += u.size();
        v.push_back(u);
    }
    if(sum < k || v.size() > k){
        cout << -1 << '\n';
        return 0;
    }
    int rem = k-v.size();
    for(auto u: v){
        if(rem == 0){
            cout << u.size() << ' ';
            for(int i: u) cout << i+1 << ' ';
            cout << '\n';
        }else if(rem < u.size()-1){
            for(int i = 0; i < rem; i++){
                cout << 1 << ' ' << u[i]+1 << '\n';
            }
            cout << u.size()-rem << ' ';
            for(int i = rem; i < u.size(); i++){
                cout << u[i]+1 << ' ';
            }
            cout << '\n';
            rem = 0;
        }else{
            rem -= u.size()-1;
            for(int i: u){
                cout << 1 << ' ' << i+1 << '\n';
            }
        }
    }
}