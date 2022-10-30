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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

const int N = 100000;
int cum_max[N+2];

void solve(){
    int n, k; cin >> n >> k;
    int a_max = 0;
    int a_min = N;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        chmax(a_max, a[i]);
        chmin(a_min, a[i]);
        if(cum_max[a[i]] == 0) cum_max[a[i]] = a[i];
    }
    for(int x = 1; x <= N; x++){
        chmax(cum_max[x], cum_max[x-1]);
    }
    
    int ans = N;
    if(a_max < k){
        ans = 0;
    }
    int x_max = 0;
    for(int i = 0; i < n; i++){
        int p = min(k, a[i]);
        chmax(x_max, a[i]/p);
        // cout << p << ' ';
    }
    // cout << endl;

    for(int min_x = 1; min_x <= a_min; min_x++){
        chmin(ans, x_max-min_x);
        if(min_x == a_min) break;
        bool ok = true;
        for(int p = 1; p*min_x <= N && p <= k; p++){
            int l = p*min_x;
            int r = min(N, p*(min_x+1)-1);
            bool exist = cum_max[r] >= l;
            if(!exist) continue;
            if(p == 1) {
                ok = false;
                break;
            }
            chmax(x_max, cum_max[r]/(p-1));
        }
        if(!ok) break;
    }
    cout << ans << endl;
    for(int x = 1; x <= N; x++){
        cum_max[x] = 0;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}