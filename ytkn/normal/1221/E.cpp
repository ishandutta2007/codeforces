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
    int a, b; cin >> a >> b;
    string s; cin >> s;
    int cnt = 0;
    vector<int> v;
    for(char c: s){
        if(c == 'X'){
            if(cnt != 0 && cnt >= b) v.push_back(cnt);
            cnt = 0;
        }else{
            cnt++;
        }
    }
    if(cnt != 0 && cnt >= b) v.push_back(cnt);
    for(int x: v){
        if(x >= b && x <= a-1){
            cout << "NO" << endl;
            return;
        }
    }
    sort(v.begin(), v.end());
    auto lose = [&](int x){
        if(x >= b && x <= a-1) return true;
        if(x >= 2*b) return true;
        return false;
    };
    int cnt_lose = 0;
    for(int x: v){
        if(lose(x)) cnt_lose++;
    }
    if(cnt_lose >= 2){
        cout << "NO" << endl;
        return;
    }
    if(v.empty()){
        cout << "NO" << endl;
        return;
    }
    int x = v.back();
    int m = v.size();
    bool win = false;
    for(int l = 0; l+a <= x; l++){
        if(lose(l)) continue;
        if(lose(x-(l+a))) continue;
        int mm = m-1;
        if(l >= a) mm++;
        if(x-(l+a) >= a) mm++;
        if(mm%2 == 0) win = true;
    }
    if(win) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int q; cin >> q;
    while(q--) solve();
}