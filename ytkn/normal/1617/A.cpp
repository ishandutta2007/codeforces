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
    string s, t; cin >> s >> t;
    string ans;
    string tmp;
    for(char c: s){
        if(c != 'a' && c != 'b'  && c != 'c' ) tmp += c;
    }
    sort(tmp.begin(), tmp.end());
    vector<int> cnt(26);
    for(char c: s) cnt[c-'a']++;
    if(t == "abc" && cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
        // abc
        for(char c: s){
            if(c == 'a') ans += c;
        }
        for(char c: s){
            if(c == 'c') ans += c;
        }
        for(char c: s){
            if(c == 'b') ans += c;
        }
    }else{
        for(char c: s){
            if(c == 'a') ans += c;
        }
        for(char c: s){
            if(c == 'b') ans += c;
        }
        for(char c: s){
            if(c == 'c') ans += c;
        }
    }
    ans += tmp;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}