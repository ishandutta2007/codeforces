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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        if(a[0]%2 == 0){
            cout << "cslnb" << endl;
        }else{
            cout << "sjfnb" << endl;
        }
        return 0;
    }
    map<int, int> count;
    for(int i = 0; i < n; i++){
        if(count.count(a[i])) count[a[i]]++;
        else count[a[i]] = 1;
    }
    if(count.count(0) && count[0] >= 2){
        cout << "cslnb" << endl;
        return 0;
    }
    int cnt_large = 0;
    for(auto [x, c]: count){
        if(c >= 3) {
            cout << "cslnb" << endl;
            return 0;
        }
        if(c == 2) {
            if(count.count(x-1) > 0){
                cout << "cslnb" << endl;
                return 0;
            }
            cnt_large++;
        }
    }
    if(cnt_large >= 2){
        cout << "cslnb" << endl;
        return 0;
    }
    ll a_sum = accumulate(a.begin(), a.end(), 0ll);
     if(a_sum == 0){
        cout << "cslnb" << endl;
        return 0;
    }
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(i >= 2){
            sum += i;
        }
    }
    ll diff = a_sum-sum;
    if(diff%2 == 0){
        cout << "sjfnb" << endl;
    }else{
        cout << "cslnb" << endl;
    }
}