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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t = s;
    vector<int> ans(n);
    int rem = k;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(k%2 == 0){
                if(rem > 0){
                    ans[i] = 1;
                    rem--;
                    t[i] = '1';
                }
            }else{
                t[i] = '1';
            }
        }else{
            if(k%2 == 1){
                if(rem > 0){
                    ans[i] = 1;
                    rem--;
                }else{
                    t[i] = '0';
                }
            }
        }
    }
    ans.back() += rem;
    if(rem%2 == 1){
        if(t.back() == '0') t.back() = '1';
        else t.back() = '0';
    }
    cout << t << endl;
    print_vector(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}