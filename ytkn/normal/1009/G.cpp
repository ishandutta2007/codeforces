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
    string s; cin >> s;
    vector<int> rem(6);
    for(char c: s) rem[c-'a']++;
    int n = s.size();
    vector<int> v(n, 63);
    vector<int> cnt(64);
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int pos; string t; cin >> pos >> t; pos--;
        int s = 0;
        for(char c: t) s |= (1<<(c-'a'));
        v[pos] &= s;
    }
    for(int i = 0; i < n; i++) cnt[v[i]]++;
    vector<int> cnt_connected(64);
    for(int s = 0; s < 64; s++){
        for(int t = 0; t < 64; t++){
            if(t&s) cnt_connected[t] += cnt[s];
        }
    }
    vector<int> rem_set(64);
    for(int s = 0; s < 64; s++){
        for(int i = 0; i < 6; i++){
            if(s&(1<<i)) rem_set[s] += rem[i];
        }
    }
    auto ok = [&]() -> bool{
        for(int s = 0; s < 64; s++){
            if(cnt_connected[s] < rem_set[s]) return false;
        }
        return true;
    };
    if(!ok()){
        cout << "Impossible" << endl;
        return 0;
    }
    string ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            if((v[i]&(1<<j)) == 0) continue;
            for(int s = 0; s < 64; s++){
                if(s&(1<<j)) rem_set[s]--;
                if(s&v[i]) cnt_connected[s]--;
            }

            if(ok()){
                ans += 'a'+j;
                break;
            }

            for(int s = 0; s < 64; s++){
                if(s&(1<<j)) rem_set[s]++;
                if(s&v[i]) cnt_connected[s]++;
            }
        }
    }
    cout << ans << endl;
}