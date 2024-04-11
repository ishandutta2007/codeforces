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


vector<int> z_algorithm(string s){
    int n = s.size();
    vector<int> ans(n);
    ans[0] = n;
    int i = 1, j = 0;
    while(i < s.size()){
        while(i+j < s.size() && s[i+j] == s[j]) j++;
        if(j == 0) {
            i++;
            continue;
        }
        ans[i] = j;
        int k = 1;
        while(k < j && ans[k]+k < j){
            ans[i+k] = ans[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    string ans;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(i == 0){
            ans += s;
            continue;
        }
        int m = s.size();
        string t = s;
        if(ans.size() >= m){
            t += ans.substr(ans.size()-m, m);
        }else{
            t += ans;
        }
        auto v = z_algorithm(t);
        for(int i = m; i < t.size(); i++){
            if(i+v[i] == t.size()){
                ans += s.substr(v[i], m-v[i]);
                break;
            }
            if(i+1 == t.size()) ans += s;
        }
    }
    cout << ans << endl;
}