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
    int n; cin >> n;
    vector<int> a(n);
    int g = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    for(int i = 0; i < n; i++) a[i] /= g;
    int asum = accumulate(a.begin(), a.end(), 0);
    if(asum%2 == 1){
        cout << 0 << endl;
        return 0;
    }
    auto dp = vec2d(2, asum+1, false);
    dp[0][0] = true;
    for(int i = 0; i < n; i++){
        int pre = i%2;
        int cur = pre^1;
        for(int j = 0; j <= asum; j++){
            dp[cur][j] = false;
        }
        for(int j = 0; j <= asum; j++){
            if(dp[pre][j]) {
                dp[cur][j] = true;
                dp[cur][j+a[i]] = true;
            }
        }
    }
    if(dp[n%2][asum/2]){
        int x =-1;
        for(int i = 0; i < n; i++){
            if(a[i]%2 == 1) x = i;
        }
        cout << 1 << endl;
        cout << x+1 << endl;
    }else{
        cout << 0 << endl;
    }
}