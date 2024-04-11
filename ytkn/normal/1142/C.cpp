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
struct line {
    line(T a, T b, T c): a(a), b(b), c(c){};
    T a, b, c;
};

template<typename T>
ostream& operator<<(ostream& os, const line<T>& l){
    os << l.a << "*x + " << l.b << "*y+ " << l.c;
    return os;
}

template<typename T>
inline T add(T a, T b){
    return a+b;
}

const double eps = 1e-10;

inline double add(double a, double b){
    if(abs(a+b) < eps*(abs(a)+abs(b))) return 0.0;
    return a+b;
}

template<typename T>
class point {
    public:
    point<T>(T x, T y): x(x), y(y){};
    point<T>(): x(0), y(0){};
    T x, y;
    point<T> operator + (point<T> p){
        return point<T>(add(x, p.x), add(y, p.y));
    };
    point<T> operator - (point<T> p){
        return point<T>(add(x, -p.x), add(y, -p.y));
    };
    point<T> operator * (T d){
        return point<T>(x*d, y*d);
    };
    T dot(point<T> p){
        return add(x*p.x, y*p.y);
    };
    T det(point<T> p){
        return add(x*p.y, -y*p.x);
    };
};

template<typename T>
bool comp_p(point<T> p, point<T> q){
    if(p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

template<typename T>
vector<point<T>> convex_hull(vector<point<T>> ps){
    int n = ps.size();
    sort(ps.begin(), ps.end(), comp_p<T>);
    vector<point<T>> ans;
    for(int i = 0; i < n; i++){
        while(ans.size() > 1 && (ans.back()-ans[ans.size()-2]).det(ps[i] - ans.back()) <= 0) ans.pop_back();
        ans.push_back(ps[i]);
    }
    int bottom_size = ans.size();
    for(int i = n-2; i >= 0; i--){
        while(ans.size() > bottom_size && (ans.back()-ans[ans.size()-2]).det(ps[i] - ans.back()) <= 0) ans.pop_back();
        ans.push_back(ps[i]);
    }
    ans.pop_back();
    return ans;
}

using P = point<ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> x(n), y(n);
    map<int, ll> max_y;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if(max_y.count(x[i])) {
            chmax(max_y[x[i]], y[i]);
        }else{
            max_y[x[i]] = y[i];
        }
    }
    if(n == 2){
        if(x[0] != x[1]) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }else if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    vector<P> points;
    for(int i = 0; i < n; i++){
        if(max_y[x[i]] == y[i]){
            points.push_back(P(x[i], y[i]-x[i]*x[i]));
        }
    }
    auto ch = convex_hull(points);
    int m = ch.size();
    int ans = 0;
    for(int i = 0; i < m; i++){
        int j = (i+1)%m;
        // cout << ch[i].x << ' ' << ch[i].y << "->" << ch[j].x << ' ' << ch[j].y << endl;
        if(ch[i].x > ch[j].x) ans++;
    }
    cout << ans << endl;
}