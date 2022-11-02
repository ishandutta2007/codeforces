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

ll calc_sum(ll x){
    return (x*(x+1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; ll x; cin >> n >> x;
    vector<ll> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = 0; i < n; i++){
        d.push_back(d[i]);
    }
    ll sum = 0;
    ll tmp = 0;
    int r = 0;
    ll ans = 0;
    for(int l = 0; l < n; l++){
        while(sum+d[r] < x){
            sum += d[r];
            tmp += calc_sum(d[r]);
            r++;
        }
        int rem = x-sum;
        chmax(ans, tmp+calc_sum(rem));
        sum -= d[l];
        tmp -= calc_sum(d[l]);
    }
    sum = 0;
    tmp = 0;
    r = 0;
    reverse(d.begin(), d.end());
    for(int l = 0; l < n; l++){
        while(sum+d[r] < x){
            sum += d[r];
            tmp += calc_sum(d[r]);
            r++;
        }
        int rem = x-sum;
        chmax(ans, tmp+calc_sum(d[r])-calc_sum(d[r]-rem));
        sum -= d[l];
        tmp -= calc_sum(d[l]);
    }
    cout << ans << endl;
}