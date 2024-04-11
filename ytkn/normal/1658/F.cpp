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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = s[i]-'0';
    auto cumsum = Cumsum<int>(v);
    int sum = cumsum.sum(0, n);
    int g = gcd(sum, n);
    if(((ll)sum*(ll)m)%n != 0){
        cout << -1 << endl;
        return;
    }
    int x = ((ll)sum*(ll)m)/n;
    for(int l = 0; l < n; l++){
        if(l+m > n){
            int r = (l+m)%n;
            int sum = cumsum.sum(l, n)+cumsum.sum(0, r);
            if(sum == x){
                cout << 2 << endl;
                cout << 1 << ' ' << r << endl;
                cout << l+1 << ' ' << n << endl;
                return;
            }
        }else{
            int r = l+m;
            int sum = cumsum.sum(l, r);
            if(sum == x){
                cout << 1 << endl;
                cout << l+1 << ' ' << r << endl;
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}