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
    ll a, b, c; cin >> a >> b >> c;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    double ans = abs(x2-x1)+abs(y2-y1);
    if(a == 0 || b == 0){
        cout << ans << endl;
        return 0;
    }
    double xx1 = -((double)(b*y1+c))/(double)a;
    double xx2 = -((double)(b*y2+c))/(double)a;

    double yy1 = -((double)(a*x1+c))/(double)b;
    double yy2 = -((double)(a*x2+c))/(double)b;

    auto dist = [&](double x1, double y1, double x2, double y2){
        double dx = x2-x1;
        double dy = y2-y1;
        return sqrt(dx*dx+dy*dy);
    };

    chmin(ans, abs(x1-xx1)+dist(xx1, y1, xx2, y2)+abs(xx2-x2));
    chmin(ans, abs(x1-xx1)+dist(xx1, y1, x2, yy2)+abs(yy2-y2));
    chmin(ans, abs(y1-yy1)+dist(x1, yy1, xx2, y2)+abs(xx2-x2));
    chmin(ans, abs(y1-yy1)+dist(x1, yy1, x2, yy2)+abs(yy2-y2));
    cout << ans << endl;
}