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

bool is_rbs(string s){
    int n = s.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') sum++;
        else sum--;
        if(sum < 0) return false;
    }
    return sum == 0;
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    if(n%2 == 1){
        cout << "NO" << '\n';
        return;
    }
    int m = n/2;
    vector<int> rem(2, m);
    for(int i = 0; i < n; i++){
        if(s[i] == '(') rem[0]--;
        if(s[i] == ')') rem[1]--;
    }
    
    string t = s;
    int last_open = -1;
    int first_close = -1;
    for(int i = 0; i < n; i++){
        if(t[i] != '?') continue;
        if(rem[0] > 0){
            t[i] = '(';
            rem[0]--;
            last_open = i;
        }else{
            t[i] = ')';
            rem[1]--;
            if(first_close == -1) first_close = i;
        }
    }
    if(!is_rbs(t)){
        cout << "NO" << '\n';
        return;
    }
    if(last_open == -1 || first_close == -1){
        cout << "YES" << '\n';
        return;
    }
    swap(t[last_open], t[first_close]);
    if(is_rbs(t)){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}