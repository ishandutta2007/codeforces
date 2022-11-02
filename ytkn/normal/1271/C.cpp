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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, sx, sy; cin >> n >> sx >> sy;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    auto count = [&](int xx, int yy)->int{
        if(xx < 0 || yy < 0) return 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            bool ok = true;
            if(xx > sx){
                if(x[i] <= sx) ok = false;
            }else if(xx < sx){
                if(x[i] >= sx) ok = false;
            }else if(yy > sy){
                if(y[i] <= sy) ok = false;
            }else{
                assert(yy < sy);
                if(y[i] >= sy) ok = false;
            }
            if(ok) ans++;
        }
        return ans;
    };
    int ans = 0;
    int ans_x = -1, ans_y = -1;
    for(int k = 0; k < 4; k++){
        int xx = sx+dx[k], yy = sy+dy[k];
        if(chmax(ans, count(xx, yy))){
            ans_x = xx;
            ans_y = yy;
        }
    }
    cout << ans << endl;
    cout << ans_x << ' ' << ans_y << endl;
}