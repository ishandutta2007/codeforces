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
    int n, a, b; cin >> n >> a >> b;
    if(max(a, b) > (n-1)/2){
        cout << -1 << endl;
        return;
    }
    if(a+b > n-2){
        cout << -1 << endl;
        return;
    }
    if(abs(a-b) >= 2){
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    int l = 1, r = n;
    if(a == b){
        for(int i = 0; i < a; i++){
            ans.push_back(l); l++;
            ans.push_back(r); r--;
        }
        for(int x = l; x <= r; x++) ans.push_back(x);
    }else if(a > b){
        ans.push_back(l); l++;
        for(int i = 0; i < a; i++){
            ans.push_back(r); r--;
            if(i == a-1) break;
            ans.push_back(l); l++;
        }
        for(int x = r; x >= l; x--) ans.push_back(x);
    }else{
        ans.push_back(r); r--;
        for(int i = 0; i < b; i++){
            ans.push_back(l); l++;
            if(i == b-1) break;
            ans.push_back(r); r--;
        }
        for(int x = l; x <= r; x++) ans.push_back(x);
    }
    for(int i = 1; i < n-1; i++){
        if(ans[i-1] < ans[i] && ans[i] > ans[i+1]) a--;
        if(ans[i-1] > ans[i] && ans[i] < ans[i+1]) b--;
    }
    assert(a == 0);
    assert(b == 0);
    print_vector(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}