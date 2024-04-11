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

void solve(){
    string s; cin >> s;
    int n = s.size();
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    if(s == s_rev){
        cout << s << endl;
        return;
    }
    string ans;
    // debug_value(s);
    // debug_value(s_rev);
    for(int i = 0; i*2 < n; i++){
        if(s[i] != s_rev[i]){
            // debug_value(i)
            int rem = n-i*2;
            string t = s.substr(i, rem);
            string t_rev = t;
            reverse(t_rev.begin(), t_rev.end());
            string tt = t+t_rev;
            auto u = z_algorithm(tt);
            for(int j = rem; j < 2*rem; j++){
                if(j+u[j] == 2*rem){
                    string ss = s.substr(0, i);
                    string tmp;
                    tmp = ss;
                    tmp += tt.substr(j, 2*rem-j);
                    reverse(ss.begin(), ss.end());
                    tmp += ss;
                    ans = tmp;
                    break;
                }
            }
            tt = t_rev+t;
            u = z_algorithm(tt);
            for(int j = rem; j < 2*rem; j++){
                if(j+u[j] == 2*rem){
                    string ss = s.substr(0, i);
                    string tmp;
                    tmp = ss;
                    tmp += tt.substr(j, 2*rem-j);
                    reverse(ss.begin(), ss.end());
                    tmp += ss;
                    if(tmp.size() > ans.size()) ans = tmp;
                    break;
                }
            }
            break;
        }   
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