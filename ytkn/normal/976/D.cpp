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

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        int d; cin >> d;
        dq.push_back(d);
    }
    int rem = dq.back()+1;
    vector<P> edges;
    int mx = dq.back();
    while(rem){
        if(!dq.empty() && dq.front() == 0){
            while(rem > dq.back()+1){
                rem--;
            }
            dq.pop_front();
        }else{
            for(int i = 0; i < rem-1; i++) edges.push_back(P(i, rem-1));
            if(!dq.empty() &&  dq.back() == rem-1){
                dq.pop_back();   
            }
            for(int &x: dq) x--;
            rem--;
        }
    }
    cout << edges.size() << endl;
    vector<int> cnt(mx+1);
    for(auto [a, b]: edges) {
        cout << a+1 << ' ' << b+1 << '\n';
        cnt[a]++;
        cnt[b]++;
    }
    // set<int> st;
    // for(int x: cnt) st.insert(x);
    // for(int x: st) cout << x << ' ';
    // cout << endl;
}