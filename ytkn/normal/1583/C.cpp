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
    vector<bool> ok(m, true);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            if(s[i][j+1] == 'X' && s[i+1][j] == 'X'){
                ok[j+1] = false;
            }
        }
    }
    vector<int> cumsum(m);
    for(int i = 1; i < m; i++){
        if(!ok[i]) cumsum[i] = cumsum[i-1]+1;
        else cumsum[i] = cumsum[i-1];
    }
    int q; cin >> q;
    while(q--){
        int x1, x2; cin >> x1 >> x2; x1--; x2--;
        if(cumsum[x2]-cumsum[x1] == 0) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
}