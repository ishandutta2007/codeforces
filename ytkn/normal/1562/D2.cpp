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
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

template <typename T>
class OffsetVec{
    public:
	int n;
    vector<T> v;
	T& operator[](int x) {
        return v[x+n];
	}
    void print(){
        for(int i = -n; i <= n; i++) cout << v[i+n] << ' ';
        cout << endl;
    }
    OffsetVec(int _n){
        n = _n;
        v = vector<T>(2*n+1);
    }
    OffsetVec(int _n, T x){
        n = _n;
        v = vector<T>(2*n+1, x);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int x = s[i] == '+' ? 1 : -1;
        if(i%2 == 1) x = -x;
        v[i] = x;
    }
    auto v_cumsum = vector<int>(n+1);
    for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    auto sect_sum = [&](int l, int r){
        return v_cumsum[r]-v_cumsum[l];
    };
    OffsetVec<vector<int>> idx(n);
    for(int i = 0; i <= n; i++) idx[v_cumsum[i]].push_back(i);
    while(q--){
        int l, r; cin >> l >> r; l--;
        int x = sect_sum(l, r);
        if(x == 0){
            cout << 0 << endl;
            continue;
        }
        int ls = v_cumsum[l];
        if(x%2 == 0){
            int k = x/2;
            int sgn = x > 0 ? 1 : -1;
            cout << 2 << endl;
            cout << *lower_bound(idx[ls+k+sgn].begin(), idx[ls+k+sgn].end(), l) << ' ' << *lower_bound(idx[ls+sgn].begin(), idx[ls+sgn].end(), l) << endl;
        }else{
            int k = x/2;
            int sgn = x > 0 ? 1 : -1;
            cout << 1 << endl;
            cout << *lower_bound(idx[ls+k+sgn].begin(), idx[ls+k+sgn].end(), l) << endl;
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