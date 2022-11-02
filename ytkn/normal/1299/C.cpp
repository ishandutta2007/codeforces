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
#include <stack>

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
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<double> a(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
    }
    auto cumsum = Cumsum<double>(a);
    vector<int> nx(n);
    vector<int> min_ave(n);
    stack<int> st;
    st.push(n);
    for(int l = n-1; l >= 0; l--){
        st.push(l+1);
        nx[l] = l+1;
        while(st.top() != n){
            st.pop();
            int r = st.top();
            if(cumsum.sum(l, nx[l])*(r-l) < cumsum.sum(l, r)*(nx[l]-l)){
                st.push(nx[l]);
                break;
            }
            nx[l] = r;
        }
    }
    // print_vector(nx);
    vector<double> ans(n);
    int cur = 0;
    while(cur != n){
        double ave = cumsum.sum(cur, nx[cur])/(nx[cur]-cur);
        for(int i = cur; i < nx[cur]; i++){
            ans[i] = ave;
        }
        cur = nx[cur];
    }
    print_vector(ans);
}