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
    vector<ll> a(n);
    vector<bool> exact(n);
    ll exact_sum = 0, no_exact_sum = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        ll x = 0;
        int point_pos = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '.') point_pos = j;
        }
        exact[i] = s.substr(point_pos+1, 5) == "00000";
        if(s[0] == '-'){
            for(int j = 1; j < point_pos; j++){
                x = x*10+(s[j]-'0');
            }
            if(exact[i]) a[i] = -x;
            else a[i] = -x-1;
        }else{
            for(int j = 0; j < point_pos; j++){
                x = x*10+(s[j]-'0');
            }
            a[i] = x;
        }
        if(exact[i]) exact_sum += a[i];
        else no_exact_sum += a[i];
    }
    int diff = -exact_sum-no_exact_sum;
    int rem = diff;
    vector<bool> is_floor(n, true);
    for(int i = 0; i < n; i++){
        if(exact[i]) continue;
        if(rem > 0){
            is_floor[i] = false;
            rem--;
        }
    }
    for(int i = 0; i < n; i++){
        if(is_floor[i]) cout << a[i] << "\n";
        else cout << a[i]+1 << "\n";
    }
}