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
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = s[i]-'0';
    auto ok_same = [&](){
        for(int i = k; i < n; i++){
            int j = i%k;
            if(v[i] > v[j]) return false;
            if(v[i] < v[j]) return true;
        }
        return true;
    };
    if(ok_same()){
        cout << n << endl;
        for(int i = 0; i < n; i++) cout << v[i%k];
        cout << endl;
        return 0;
    }
    int j = 0;
    for(int i = k-1; i >= 0; i--){
        if(v[i] != 9){
            j = i;
            break;
        }
    }
    v[j]++;
    for(int i = j+1; i < k; i++){
        v[i] = 0;
    }
    cout << n << endl;
    for(int i = 0; i < n; i++) cout << v[i%k];
    cout << endl;
}