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


/**
 * https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
 * Project Eular
 */

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

istream & operator >> (istream &in,  __int128_t &m){
    string s; cin >> s;
    m = parse(s);
    return in;
}


ostream &operator<<(std::ostream &dest, __int128_t value) {
    ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = end(buffer);
        do {
        --d;
        *d = "0123456789"[tmp % 10];
        tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
        --d;
        *d = '-';
        }
        int len = end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
        dest.setstate(ios_base::badbit);
        }
    }
    return dest;
}

using ll = __int128_t;

void solve(){
    int n, m; cin >> n >> m;
    auto c = vec2d(n, m, 0ll);
    vector<ll> sum(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
            sum[i] += c[i][j]*(ll)(m-j);
        }
    }
    ll mx = *max_element(sum.begin(), sum.end());
    ll mn = *min_element(sum.begin(), sum.end());
    for(int i = 0; i < n; i++){
        if(sum[i] == mn){
            cout << i+1 << ' ';
        }
    }
    cout << mx-mn << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}