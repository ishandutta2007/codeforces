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
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<bool> is_palindrome(n);
    for(int i = 0; i < n; i++){
        string t = s[i];
        reverse(t.begin(), t.end());
        if(s[i] == t) is_palindrome[i] = true;
    }
    vector<int> p(n, -1);
    for(int i = 0; i < n; i++){
        if(is_palindrome[i]) continue;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            string t = s[j];
            reverse(t.begin(), t.end());
            if(s[i] == t) p[i] = j;
        }
    }
    string ans;
    for(int i = 0; i < n; i++){
        if(is_palindrome[i]) {
            ans = s[i];
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(p[i] == -1) continue;
        if(p[i] < i) continue;
        ans = s[i]+ans+s[p[i]];
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}