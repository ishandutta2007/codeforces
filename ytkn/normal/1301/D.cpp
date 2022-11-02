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

using P = pair<int, string>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    if(k > 4*n*m-2*n-2*m){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(k <= m-1){
        cout << 1 << endl;
        cout << k << ' ' << "R" << endl;
        return 0;
    }
    if(k <= 2*m-2){
        cout << 2 << endl;
        cout << m-1 << ' ' << "R" << endl;
        cout << k-(m-1) << ' ' << "L" << endl;
        return 0;
    }
    vector<P> ans;
    if(m > 1){
        ans.push_back(P(m-1, "R"));
        ans.push_back(P(m-1, "L"));
    }
    k -= 2*m-2;
    for(int i = 0; i < n-1; i++){
        if(k == 0) break;
        ans.push_back(P(1, "D"));
        k--;
        if(k == 0) break;
        if(m == 1) continue;
        int x = k/3;
        chmin(x, m-1);
        if(x != 0) ans.push_back(P(x, "RUD"));
        k -= x*3;
        if(k == 0) break;
        if(x == m-1){
            if(k >= m-1){
                ans.push_back(P(m-1, "L"));
                k -= m-1;
            }else{
                ans.push_back(P(k, "L"));
                k = 0;
            }
        }else{
            string RUD = "RUD";
            for(int i = 0; i < k; i++){
                ans.push_back(P(1, string(1, RUD[i])));
            }
            k = 0;
            break;
        }
    }
    if(k > 0){
        ans.push_back(P(k, "U"));
    }
    cout << ans.size() << endl;
    for(auto [c, s]: ans) cout << c << ' ' << s << endl;
}