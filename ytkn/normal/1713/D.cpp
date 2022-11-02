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

void test(int n){
    int m = 1<<n;
    int sum = 0;
    int mx = ((1<<(n+1))+2)/3;
    while(true){
        if(m == 1) break;
        if(m == 2){
            sum++;
            break;
        }
        sum += 2*m/4;
        m /= 4;
    }
    cout << sum << ' ' << mx << endl;
}

void solve(){
    int n; cin >> n;
    auto ask = [&](int i, int j){
        cout << "? " << i+1 << ' ' << j+1 << endl;
        int ans; cin >> ans;
        return ans;
    };
    auto verify = [&](int i){
        cout << "! " << i+1 << endl;
    };
    int m = 1<<n;
    vector<int> rem(m);
    iota(rem.begin(), rem.end(), 0);
    while(rem.size() > 1){
        vector<int> nx;
        if(rem.size() == 2){
            int a = rem[0], b = rem[1];
            int ans = ask(a, b);
            if(ans == 1){
                nx.push_back(a);
            }else if(ans == 2){
                nx.push_back(b);
            }else{
                assert(false);
            }
        }else{
            for(int i = 0; i < rem.size(); i+=4){
                int a = rem[i], b = rem[i+1], c = rem[i+2], d = rem[i+3];
                int ans0 = ask(a, c);
                if(ans0 == 1){ // a
                    int ans1 = ask(a, d);
                    if(ans1 == 1){ // a
                        nx.push_back(a);
                    }else if(ans1 == 2){ // d
                        nx.push_back(d);
                    }else{
                        assert(false);
                    }
                }else if(ans0 == 2){ // c
                    int ans1 = ask(b, c);
                    if(ans1 == 1){ // b
                        nx.push_back(b);
                    }else if(ans1 == 2){ // c
                        nx.push_back(c);
                    }else{
                        assert(false);
                    }
                }else{ // 
                    int ans1 = ask(b, d);
                    if(ans1 == 1){ // b
                        nx.push_back(b);
                    }else if(ans1 == 2){ // d
                        nx.push_back(d);
                    }else{
                        assert(false);
                    }
                }
            }
        }
        rem = nx;
    }
    verify(rem[0]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // for(int i = 1; i <= 17; i++) test(i);
    int t; cin >> t;
    while(t--) solve();
}