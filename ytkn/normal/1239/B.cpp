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
    string s; cin >> s;
    int shift = 0;
    for(int i = 0; i < n; i++){
        int j = (i-1+n)%n;
        if(s[j] == ')' && s[i] == '('){
            shift = i;
            string t;
            for(int k = i; k < n; k++) t += s[k]; 
            for(int k = 0; k < i; k++) t += s[k];
            s = t; 
            break;
        }
    }
    // debug_value(s);
    vector<int> sum(n+1);
    for(int i = 0; i < n; i++){
        int x = s[i] == '(' ? 1 : -1;
        sum[i+1] = sum[i]+x;
    }
    if(sum[n] != 0){
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    int sum_min = *min_element(sum.begin(), sum.end());
    vector<vector<int>> indices(3);
    for(int i = 0; i <= n; i++){
        int d = sum[i]-sum_min;
        if(d <= 2) indices[d].push_back(i);
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(sum[i] == sum_min) ans++;
    }
    int ans_l = 0, ans_r = 0;
    auto count = [&](int x, int l, int r)->int{ // [l, r)
        return lower_bound(indices[x].begin(), indices[x].end(), r) - lower_bound(indices[x].begin(), indices[x].end(), l);
    };
    // print_vector(sum);
    { // sum_min-1
        vector<int> v = {0, n};
        for(int i: indices[0]) v.push_back(i);
        sort(v.begin(), v.end());
        int m = v.size();
        for(int i = 0; i+1 < m; i++){
            if(v[i] == v[i+1]) continue;
            int tmp = count(1, v[i]+1, v[i+1]);
            if(chmax(ans, tmp)){
                ans_l = (v[i]+shift)%n;
                ans_r = (v[i+1]-1+shift)%n;
                if(ans_l > ans_r) swap(ans_l, ans_r);
            }
        }
    }
    { // sum_min
        vector<int> v = {0, n};
        for(int i: indices[1]) v.push_back(i);
        sort(v.begin(), v.end());
        int m = v.size();
        for(int i = 0; i+1 < m; i++){
            if(v[i] == v[i+1]) continue;
            if(sum[v[i]+1] == sum_min) continue;
            if(sum[v[i+1]-1] == sum_min) continue;
            int tmp = count(2, v[i]+1, v[i+1])+count(0, 0, v[i])+count(0, v[i+1], n);
            if(chmax(ans, tmp)){
                ans_l = (v[i]+shift)%n;
                ans_r = (v[i+1]-1+shift)%n;
                if(ans_l > ans_r) swap(ans_l, ans_r);
            }
        }
    }
    if(sum_min+1 <= 0){ // sum_min+1
        int l = indices[0][0];
        int r = indices[0].back();
        int li = -1, ri = -1;
        for(int i = l-1; i >= 0; i--){
            if(s[i] == ')') {
                li = i;
                break;
            }
        }
        for(int i = r; i < n; i++){
            if(s[i] == '(') {
                ri = i;
                break;
            }
        }
        if(li != -1 && ri != -1){
            string t = s;
            swap(t[li], t[ri]);
            vector<int> sum(n+1);
            for(int i = 0; i < n; i++){
                int x = t[i] == '(' ? 1 : -1;
                sum[i+1] = sum[i]+x;
            }
            int sum_min = *min_element(sum.begin(), sum.end());
            int tmp = 0;
            for(int i = 0; i < n; i++){
                if(sum[i] == sum_min) tmp++;
            }
            if(chmax(ans, tmp)){
                ans_l = (li+shift)%n;
                ans_r = (ri+shift)%n;
                if(ans_l > ans_r) swap(ans_l, ans_r);
            }
        }
    }
    if(sum_min+2 <= 0){ // sum_min+2
        int l = min(indices[0][0], indices[1][0]);
        int r = max(indices[0].back(), indices[1].back());
        int li = -1, ri = -1;
        for(int i = l-1; i >= 0; i--){
            if(s[i] == ')') {
                li = i;
                break;
            }
        }
        for(int i = r; i < n; i++){
            if(s[i] == '(') {
                ri = i;
                break;
            }
        }
        if(li != -1 && ri != -1){
            string t = s;
            swap(t[li], t[ri]);
            vector<int> sum(n+1);
            for(int i = 0; i < n; i++){
                int x = t[i] == '(' ? 1 : -1;
                sum[i+1] = sum[i]+x;
            }
            int sum_min = *min_element(sum.begin(), sum.end());
            int tmp = 0;
            for(int i = 0; i < n; i++){
                if(sum[i] == sum_min) tmp++;
            }
            if(chmax(ans, tmp)){
                ans_l = (li+shift)%n;
                ans_r = (ri+shift)%n;
                if(ans_l > ans_r) swap(ans_l, ans_r);
            }
        }
    }

    cout << ans << endl;
    cout << ans_l+1 << ' ' << ans_r+1 << endl;
}