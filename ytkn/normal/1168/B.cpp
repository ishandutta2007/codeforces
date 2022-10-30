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

void test(int n){
    for(int s = 0; s < (1<<n); s++){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) v[i] = 1;
        }
        bool ok = false;
        for(int i = 0; i < n; i++){
            for(int k = 1; i+2*k < n; k++){
                if(v[i] == v[i+k] && v[i+k] == v[i+2*k]) ok = true;
                if(ok) break;
            }
            if(ok) break;
        }
        if(!ok) print_vector(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string s; cin >> s;
    int n = s.size();
    auto find = [&](int l){
        int r = min(l+9, n);
        int ans = n;
        for(int i = l; i < r; i++){
            for(int k = 1; i+2*k < r; k++){
                if(s[i] == s[i+k] && s[i+k] == s[i+2*k]) chmin(ans, i+2*k);
            }
        }
        return ans;
    };
    ll ans = 0;
    for(int l = 0; l < n; l++){
        int r = find(l);
        if(r == n) continue;
        ans += n-r;
    }
    cout << ans << endl;
}