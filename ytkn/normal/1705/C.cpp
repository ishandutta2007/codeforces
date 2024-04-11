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
    int n, c, q; cin >> n >> c >> q;
    string s; cin >> s;
    vector<ll> len(c+1);
    len[0] = n;
    vector<ll> l(c), r(c);
    for(int i = 0; i < c; i++){
        cin >> l[i] >> r[i]; l[i]--; r[i]--;
        len[i+1] = len[i]+r[i]-l[i]+1;
    }
    function<char(int, ll)> sub_solve = [&](int idx, ll pos){
        if(idx == 0) {
            return s[pos];
        }
        if(pos >= len[idx-1]) {
            pos -= len[idx-1];
            pos += l[idx-1];
        }
        return sub_solve(idx-1, pos);
    };
    while(q--){
        ll k; cin >> k; k--;
        cout << sub_solve(c+1, k) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}