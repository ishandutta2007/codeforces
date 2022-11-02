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
    int n, m; cin >> n >> m;
    int k; cin >> k;
    vector<int> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        a[i] = k+1-a[i];
    }
    int nx = 1;
    priority_queue<int, vector<int>, greater<int>> que;
    int max_size = n*m-4;
    for(int x: a){
        if(x == nx){
            nx++;
            while(!que.empty() && que.top() == nx){
                que.pop();
                nx++;
            }
            continue;
        }
        if(x != nx && (que.empty() || que.top() != nx)){
            que.push(x);
            if(que.size() > max_size){
                cout << "TIDAK" << endl;
                return;
            }
            continue;
        }
        while(true){
            if(x == nx){
                nx++;
                continue;
            }
            if(!que.empty() && que.top() == nx){
                nx++;
                que.pop();
                continue;
            }
            break;
        }
    }
    // debug_value(que.size())
    cout << "YA" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}