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

template <typename T>
class OffsetVec{
    public:
	int n;
    vector<T> v;
	T& operator[](int x) {
        return v[x+n];
	}
    void print(){
        for(int i = -n; i <= n; i++) cout << v[i+n] << ' ';
        cout << endl;
    }
    OffsetVec(int _n){
        n = _n;
        v = vector<T>(2*n+1);
    }
    OffsetVec(int _n, T x){
        n = _n;
        v = vector<T>(2*n+1, x);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(100);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        cnt[a[i]]++;
    }
    int cnt_max = *max_element(cnt.begin(), cnt.end());
    vector<int> v;
    for(int x = 0; x < 100; x++){
        if(cnt[x] == cnt_max) v.push_back(x);
    }
    if(v.size() >= 2){
        cout << n << endl;
        return 0;
    }
    int x = v[0];
    int ans = 0;
    for(int y = 0; y < 100; y++){
        if(x == y) continue;
        OffsetVec<vector<int>> indices(n);
        indices[0].push_back(0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == x){
                sum++;
            }else if(a[i] == y){
                sum--;
            }
            indices[sum].push_back(i+1);
        }
        for(int d = -n; d <= n; d++){
            if(indices[d].size() == 0) continue;
            chmax(ans,  indices[d].back()-indices[d][0]);
        }
    }
    cout << ans << endl;
}