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

int pcount[1<<15];

void init(){
    for(int s = 0; s < (1<<15); s++){
        for(int i = 0; i < 15; i++){
            if(s&(1<<i)) pcount[s]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n; cin >> n;
    vector<int> l(n), r(n);
    int mask = (1<<15)-1;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        l[i] = a&mask;
        r[i] = (a>>15)&mask;
    }
    map<vector<int>, int> mp;
    for(int s = 0; s < (1<<15); s++){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[i] = pcount[l[i]^s];
        }
        int x = v[0];
        for(int i = 0; i < n; i++) v[i] -= x;
        mp[v] = s;
    }
    for(int s = 0; s < (1<<15); s++){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[i] = pcount[r[i]^s];
        }
        int x = v[0];
        for(int i = 0; i < n; i++) v[i] -= x;
        vector<int> u(n);
        for(int i = 0; i < n; i++) u[i] -= v[i];
        if(mp.count(u)){
            int t = mp[u];
            cout << (s<<15)+t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}