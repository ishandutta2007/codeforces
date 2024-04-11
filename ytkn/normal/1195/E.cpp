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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using P = pair<int, int>;
using T = tuple<ll, int, int>;

template <class T>
class SlidingMinimum{
    public:
    deque<T> dq;
    vector<T> a;

    void push_right(int r, T x){
        assert(r == a.size());
        a.push_back(x);
        while(!dq.empty() && a[dq.back()] >= x) dq.pop_back();
        dq.push_back(r);
    }

    /**
     * NOTE: indexl
     */ 
    void pop_left(int l){
        while(!dq.empty() && dq.front() <= l) dq.pop_front();
    }

    T query(){ 
        return a[dq.front()];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, a, b; cin >> n >> m >> a >> b;
    ll g0, x, y, z; cin >> g0 >> x >> y >> z;
    auto v = vec2d(n, m, 0ll);
    auto u = vec2d(n, m-b+1, 0ll);
    ll g = g0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            v[i][j] = g;
            g = (g*x+y)%z;
        }
    }
    for(int i = 0; i < n; i++){
        auto sm = SlidingMinimum<ll>();
        int r = 0;
        for(int j = 0; j+b <= m; j++){
            while(r < j+b){
                sm.push_right(r, v[i][r]);
                r++;
            }
            u[i][j] = sm.query();
            sm.pop_left(j);
        }
    }
    ll ans = 0;
    for(int j = 0; j+b <= m; j++){
        int r = 0;
        auto sm = SlidingMinimum<ll>();
        for(int i = 0; i+a <= n; i++){
            while(r < i+a){
                sm.push_right(r, u[r][j]);
                r++;
            }
            ans += sm.query();
            // cout << sm.query() << ' ';
            sm.pop_left(i);
        }
        // cout << endl;
    }
    cout << ans << endl;
}