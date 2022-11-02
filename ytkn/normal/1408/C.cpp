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

void solve(){
    int n; double l; cin >> n >> l;
    vector<double> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto from_left = [&](double t){
        double rem = t;
        double pos = 0;
        double speed = 1.0;
        for(int i = 0; i < n; i++){
            if(speed*rem+pos >= a[i]){
                rem -= (a[i]-pos)/speed;
                speed += 1;
                pos = a[i];
            }else{
                return speed*rem+pos;
            }
        }
        return min(l, speed*rem+pos);
    };
    auto from_right = [&](double t){
        double rem = t;
        double pos = l;
        double speed = 1.0;
        for(int i = n-1; i >= 0; i--){
            if(pos-speed*rem <= a[i]){
                rem -= (pos-a[i])/speed;
                speed += 1;
                pos = a[i];
            }else{
                return pos-speed*rem;
            }
        }
        return max(0.0, pos-speed*rem);
    };
    double tl = 0.0, tr = l;
    int cnt = 50;
    while(cnt--){
        double t = (tl+tr)/2;
        if(from_left(t) < from_right(t)) tl = t;
        else tr = t;
    }
    cout << tl << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}