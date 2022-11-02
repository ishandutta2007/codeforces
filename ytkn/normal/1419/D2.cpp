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
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    auto ok = [&](int x){
        assert(x <= (n-1)/2);
        int l = 0, r = n-1;
        vector<int> large, small;
        for(int i = 0; i < x; i++){
            large.push_back(a[r]);
            small.push_back(a[l]);
            l++;
            r--;
        }
        large.push_back(a[r]); r--;
        reverse(small.begin(), small.end());
        for(int i = 0; i < x; i++){
            if(large[i] <= small[i]) return false;
            if(large[i+1] <= small[i]) return false;
        }
        return true;
    };
    auto make_ans = [&](int x) -> vector<int>{
        int l = 0, r = n-1;
        vector<int> ans;
        vector<int> large, small;
        for(int i = 0; i < x; i++){
            large.push_back(a[r]);
            small.push_back(a[l]);
            l++;
            r--;
        }
        large.push_back(a[r]); r--;
        reverse(small.begin(), small.end());
        ans.push_back(large[0]);
        for(int i = 0; i < x; i++){
            ans.push_back(small[i]);
            ans.push_back(large[i+1]);
        }
        for(int i = l; i <= r; i++){
            ans.push_back(a[i]);
        }
        return ans;
    };

    int mx = (n-1)/2;
    if(ok(mx)){
        cout << mx << endl;
        print_vector(make_ans(mx));
        return 0;
    }
    int l = 0, r = mx;
    while(r-l > 1){
        int x = (l+r)/2;
        if(ok(x)) l = x;
        else r = x;
    }
    cout << l << endl;
    print_vector(make_ans(l));
}