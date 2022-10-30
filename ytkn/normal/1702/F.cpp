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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(a[i]%2 == 0) a[i] /= 2;
    }
    map<int, int> b;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        while(x%2 == 0) x /= 2;
        if(b.count(x)) b[x]++;
        else b[x] = 1;
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int x: a){
        while(prev(b.end())->first > x){
            auto p = *prev(b.end());
            int y = p.first, c = p.second;
            b.erase(y);
            y /= 2;
            if(y == 0) continue;
            while(y%2 == 0) y /= 2;
            if(b.count(y)) b[y] += c;
            else b[y] = c;
        }
        if(b.count(x)){
            b[x]--;
            if(b[x] == 0) b.erase(x);
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}