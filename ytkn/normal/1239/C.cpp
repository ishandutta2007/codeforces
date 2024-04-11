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

using T = tuple<ll, int, int>;
using P = pair<ll, int>;
const int START_WAIT = 1;
const int FINISH = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; ll p; cin >> n >> p;
    vector<ll> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    queue<int> que;
    set<int> in_que;
    set<ll> times;
    priority_queue<int, vector<int>, greater<int>> waiting;
    vector<P> start_wait;
    bool used = false;
    auto push_que = [&](int i){
        que.push(i);
        in_que.insert(i);
    };
    auto pop_que = [&](){
        int i = que.front();
        que.pop();
        in_que.erase(i);
    };
    
    for(int i = 0; i < n; i++){
        start_wait.push_back(P(t[i], i));
        times.insert(t[i]);
    }
    sort(start_wait.begin(), start_wait.end(), greater<P>());
    vector<ll> ans(n);
    ll finish_time = -1;
    int finish_idx = -1;
    auto can_push_que = [&](int i){
        if(finish_idx != -1 && finish_idx < i) return false;
        if(que.empty()) return true;
        return *in_que.begin() > i;
    };
    while(!times.empty()){
        ll t = *times.begin();
        times.erase(t);
        while(!start_wait.empty() && start_wait.back().first == t){
            int i = start_wait.back().second;
            waiting.push(i);
            start_wait.pop_back();
        }
        if(finish_time == t){
            assert(used);
            used = false;
            finish_idx = -1;
            finish_time = -1;
        }
        if(!waiting.empty()){
            int i = waiting.top();
            if(can_push_que(i)){
                push_que(i);
                waiting.pop();
            }
        }
        if(!que.empty() && !used){
            used = true;
            int i = que.front();
            pop_que();
            times.insert(t+p);
            ans[i] = t+p;
            finish_idx = i;
            finish_time = t+p;
        }
    }
    print_vector(ans);
}