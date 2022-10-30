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
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << 1 << ' ' << 1 << endl;
        cout << -a[0] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << ' ' << 1 << endl;
    cout << -a[0] << endl;
    a[0] = 0;
    cout << 2 << ' ' << n << endl;
    for(int i = 1; i < n; i++){
        cout << a[i]*(n-1) << ' ';
        a[i] = a[i]+(ll)(n-1)*a[i];
    }
    cout << endl;
    cout << 1 << ' ' << n << endl;
    for(int i = 0; i < n; i++) cout << -a[i] << ' ';
    cout << endl;
}