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
    for(int i = 0; i < n; i++) cin >> a[i];
    int q; cin >> q;
    vector<int> t(q), x(q), p(q);
    vector<int> last_receipt(n, -1);
    for(int i = 0; i < q; i++){
        cin >> t[i];
        if(t[i] == 1) {
            cin >> p[i] >> x[i];
            p[i]--;
            last_receipt[p[i]] = i;
        }else{
            cin >> x[i];
        }
    }
    vector<int> ans = a;
    int mx_chmax = 0;
    for(int i = q-1; i >= 0; i--){
        if(t[i] == 1){
            if(last_receipt[p[i]] == i){
                ans[p[i]] = max(x[i], mx_chmax);
            }
        }else{
            chmax(mx_chmax, x[i]);
        }
    }
    for(int i = 0; i < n; i++){
        if(last_receipt[i] != -1) continue;
        ans[i] = max({ans[i], mx_chmax});
    }
    print_vector(ans);
}