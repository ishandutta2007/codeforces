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

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    vector<int> cnt(n);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
        cnt[a[i]]++;
    }
    int max_cnt = *max_element(cnt.begin(), cnt.end());
    vector<int> mn(n, inf);
    for(int i = 0; i < m; i++){
        int d = (b[i]-a[i]+n)%n;
        chmin(mn[a[i]], d);
    }
    for(int i = 0; i < n; i++){
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(cnt[j] == 0) continue;
            int d = (j-i+n)%n;
            int tmp = d+(cnt[j]-1)*n + mn[j];
            chmax(ans, tmp);
        }
        cout << ans << ' ';
    }
    cout << endl;
}