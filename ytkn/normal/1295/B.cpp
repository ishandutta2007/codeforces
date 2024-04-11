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


// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

void solve(){
    int n, x; cin >> n >> x;
    string s; cin >> s;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') sum++;
        else sum--;
    }
    if(sum < 0){
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                s[i] = '0';
            }else{
                s[i] = '1';
            }
        }
        x *= -1;
    }
    int l = 0, r = 0;
    map<int, int> mp;
    sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') sum++;
        else sum--;
        if(mp.count(sum)) mp[sum]++;
        else mp[sum] = 1;
        chmax(r, sum);
        chmin(l, sum);
    }
    if(sum == 0 && mp.count(x)){
        cout << -1 << endl;
        return;
    }
    if(sum == 0){
        cout << 0 << endl;
        return;
    }
    int cl = ceil_div(x-r, sum);
    chmax(cl, 0);
    int cr = (x-l)/sum;
    ll ans = 0;
    if(x == 0) ans = 1;
    for(int c = cl; c <= cr; c++){
        int xx = x-c*sum;
        if(mp.count(xx)) ans += mp[xx];
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}