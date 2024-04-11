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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int a_max = *max_element(a.begin(), a.end());
    deque<int> dq;
    for(int i = 0; i < n; i++) dq.push_back(a[i]);
    auto ans = vec2d(2*n, 2, 0);
    int idx = -1;
    for(int i = 0; i < 2*n; i++){
        int a = dq.front(); dq.pop_front();
        int b = dq.front(); dq.pop_front();
        ans[i][0] = a;
        ans[i][1] = b;
        if(a == a_max && idx == -1){
            idx = i;
        }
        if(a < b) swap(a, b);
        dq.push_front(a);
        dq.push_back(b);
    }
    while(q--){
        ll m; cin >> m; m--;
        if(m < idx){
            cout << ans[m][0] << ' ' << ans[m][1] << endl;
        }else{
            m -= idx;
            m %= (n-1);
            cout << ans[m+idx][0] << ' ' << ans[m+idx][1] << endl;
        }
    }
}