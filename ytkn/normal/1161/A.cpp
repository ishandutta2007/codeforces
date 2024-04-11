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
    int n, k; cin >> n >> k;
    vector<int> x(k);
    vector<int> first_time(n, -1);
    vector<int> last_time(n, -1);
    for(int i = 0; i < k; i++){
        cin >> x[i]; x[i]--;
        if(first_time[x[i]] == -1) first_time[x[i]] = i;
        last_time[x[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(first_time[i] == -1){
            ans++;
            if(i > 0 && last_time[i-1] != k) ans++;
            if(i+1 < n && last_time[i+1] != k) ans++;
            continue;
        }
        if(i > 0){
            if(last_time[i-1] == -1 || last_time[i-1] < first_time[i]) ans++;
        }
        if(i+1 < n){
            if(last_time[i+1] == -1 || last_time[i+1] < first_time[i]) ans++;
        }
    }
    cout << ans << endl;
}