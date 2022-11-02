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

const int MX = 1000000000;
using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    vector<int> horizontal;
    for(int i = 0; i < m; i++){
        int x1, x2, y; cin >> x1 >> x2 >> y;
        if(x1 != 1) continue;
        horizontal.push_back(x2);
    }
    
    x.push_back(0);
    x.push_back(MX);
    sort(horizontal.begin(), horizontal.end());
    sort(x.begin(), x.end());
    int ans = n+m;
    for(int i = 0; i+1 < x.size(); i++){
        int l = x[i], r = x[i+1];
        int cnt = horizontal.end() - lower_bound(horizontal.begin(), horizontal.end(), r);
        chmin(ans, cnt+i);
    }
    cout << ans << endl;
}