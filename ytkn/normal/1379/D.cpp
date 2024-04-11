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

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, H, M, k; cin >> n >> H >> M >> k;
    vector<int> h(n), m(n);
    for(int i = 0; i < n; i++) cin >> h[i] >> m[i];
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.push_back(m[i]);
        v.push_back(m[i]+M);
    }
    sort(v.begin(), v.end());
    auto count = [&](int l, int r){ // [l, r)
        auto pl = lower_bound(v.begin(), v.end(), l);
        auto pr = lower_bound(v.begin(), v.end(), r);
        return pr-pl;
    };
    int X = M/2;
    int ans = n;
    int ans_x = 0;
    // debug_value(count(0, 60))
    auto calc = [&](int x)->int{
        return count(x+1, x+k)+count(x+1+X, x+k+X);
    };
    for(int i = 0; i < n; i++){
        int x = m[i];
        x %= X;
        if(chmin(ans, calc(x))) ans_x = x;
        int y = m[i]-k;
        y %= X;
        y = (y+X)%X;
        if(chmin(ans, calc(y))) ans_x = y;
    }
    int departure = (ans_x+k)%X;
    cout << ans << ' ' << departure << endl;
    for(int i = 0; i < n; i++){
        bool ng = false;
        if(ans_x+1 <= m[i] && m[i] <= ans_x+k-1) ng = true;
        if(ans_x+X+1 <= m[i] && m[i] <= ans_x+X+k-1) ng = true;
        if(ans_x+X+1 <= m[i]+M && m[i]+M <= ans_x+X+k-1) ng = true;
        if(ng) cout << i+1 << ' ';
    }
    cout << endl;
}