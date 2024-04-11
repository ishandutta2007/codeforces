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

/**
 * reference
 * https://codeforces.com/contest/1336/submission/76875109
 */ 
int64_t msb(int64_t v){
  v = v | (v >>  1);
  v = v | (v >>  2);
  v = v | (v >>  4);
  v = v | (v >>  8);
  v = v | (v >> 16);
  v = v | (v >> 32);
  return v ^ (v >> 1);
}
 
struct GJ_Xor{
    vector<int64_t> V;
 
    void add(int64_t a){
        for(int64_t v : V) if(msb(v)&a) a ^= v;
        if(a > 0){
            for(int64_t& v : V) if(msb(a)&v) v ^= a;
            V.push_back(a);
            sort(V.rbegin(), V.rend());
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int x = 0;
    vector<int> cumxor(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        cumxor[i] = x^a;
        x ^= a;
    }
    if(cumxor.back() == 0){
        cout << -1 << endl;
        return 0;
    }
    GJ_Xor basis;
    basis.add(cumxor.back());
    for(int x: cumxor){
        basis.add(x);
    }
    cout << basis.V.size() << endl;
}