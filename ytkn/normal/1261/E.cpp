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

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int a_min = *min_element(a.begin(), a.end());
    if(a_min == n){
        cout << n+1 << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout  << (i == j ? 0 : 1);
            }
            cout << endl;
        }
        for(int i = 0; i < n; i++) cout << 1;
        cout << endl;
        return 0;
    }
    int cnt = 0;
    vector<P> p(n);
    for(int i = 0; i < n; i++){
        p[i] = P(a[i], i);
        if(a[i] == n) cnt++;
    }
    sort(p.begin(), p.end(), greater<P>());
    vector<int> idx(n);
    vector<int> rem(n);
    for(int i = 0; i < n; i++) {
        idx[i] = p[i].second;
        rem[i] = p[i].first;
    }
    auto ans = vec2d(n+1, n, 0);
    auto add = [&](int i, int j){
        assert(i <= n);
        assert(j < n);
        assert(i != j);
        assert(ans[i][j] == 0);
        ans[i][j] = 1;
        rem[j]--;
        assert(rem[j] >= 0);
    };
    for(int j = 0; j < n-1; j++) add(j+1, j);
    if(cnt == n-1){
        add(n, n-1);
    }else{
        add(cnt, n-1);
    }
    for(int j = 0; j < n; j++){
        int idx = 0;
        while(rem[j]){
            while(ans[idx][j] == 1 || idx == j) idx++;
            add(idx, j);
        }
    }
    cout << n+1 << endl;
    for(int i = 0; i < n+1; i++){
        vector<int> v(n);
        for(int j = 0; j < n; j++){
            v[idx[j]] = ans[i][j];
        }
        for(int j = 0; j < n; j++) cout << v[j];
        cout << endl;
    }
    for(int j = 0; j < n; j++) assert(rem[j] == 0);
}