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
    int n, m; cin >> n >> m;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    int sum = 0;
    int sum_erased = 0;
    priority_queue<int, vector<int>, greater<int>> erased;
    priority_queue<int> remaining;
    for(int i = 0; i < n; i++){
        while(!erased.empty() && !remaining.empty() && erased.top() < remaining.top()){
            int e = erased.top(); erased.pop();
            sum_erased -= e;
            int r = remaining.top(); remaining.pop();
            erased.push(r);
            remaining.push(e);
            sum_erased += r;
        }
        sum += t[i];
        while(!erased.empty() && sum - sum_erased < m){
            int e = erased.top(); erased.pop();
            remaining.push(e);
            sum_erased -= e;
        }
        while(sum - sum_erased > m){
            int r = remaining.top(); remaining.pop();
            erased.push(r);
            sum_erased += r;
        }
        remaining.push(t[i]);
        cout << erased.size() << ' ';
    }
    cout << endl;
}