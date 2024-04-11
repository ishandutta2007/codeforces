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

vector<int> make_longest(string s){
    int n = s.size()+1;
    vector<int> incereasing, decreasing;
    incereasing.push_back(0);
    for(int i = 1; i < n; i++){
        if(s[i-1] == '<') incereasing.push_back(i);
        else decreasing.push_back(i);
    }
    vector<int> ans(n);
    int cur = n-incereasing.size()+1;
    for(int i: incereasing){
        ans[i] = cur;
        cur++;
    }
    cur = n-incereasing.size();
    for(int i: decreasing){
        ans[i] = cur;
        cur--;
    }
    return ans;
}

vector<int> make_shortest(string s){
    int n = s.size()+1;
    vector<vector<int>> blocks;
    vector<int> ans;
    vector<int> buf = {0};
    for(int i = 0; i < n-1; i++){
        if(s[i] == '>'){
            blocks.push_back(buf);
            buf.clear();
        }
        buf.push_back(i+1);
    }
    blocks.push_back(buf);
    int cur = n;
    for(auto v: blocks){
        int x = cur-v.size()+1;
        for(int i: v){
            ans.push_back(x);
            x++;
        }
        cur -= v.size();
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    print_vector(make_shortest(s));
    print_vector(make_longest(s));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}