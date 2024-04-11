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
    ll n, k; cin >> n >> k;
    if(k < tri(n)){
        cout << -1 << endl;
        return 0;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    ll cur = tri(n);
    for(int i = n-1; i >= 0; i--){
        int mx = n-(n-1-i)/2;
        if(mx-p[i] > k-cur){
            p[i] += k-cur;
            cur = k;
        }else{
            cur += mx-p[i];
            p[i] = mx;
        }
    }
    vector<int> rem(n+1, 2);
    for(int i = 0; i < n; i++) rem[p[i]]--;
    vector<int> q;
    vector<int> twice, zero;
    for(int i = 1; i <= n; i++){
        if(rem[i] == 0){
            twice.push_back(i);
        }
        if(rem[i] == 2){
            zero.push_back(i);
        }
    }
    vector<int> other(n+1);
    iota(other.begin(), other.end(), 0);
    assert(twice.size() == zero.size());
    int m = twice.size();
    for(int i = 0; i < m; i++){
        other[twice[i]] = zero[i];   
        other[zero[i]] = twice[i];   
    }
    ll sum = accumulate(p.begin(), p.end(), 0ll);
    cout << sum << endl;
    for(int i = 1; i <= n; i++) cout << i << ' ';
    cout << endl;
    for(int i = 1; i <= n; i++) cout << other[i] << ' ';
    cout << endl;
}