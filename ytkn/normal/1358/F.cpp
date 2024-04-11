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

using P = pair<char, ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    if(n == 1){
        if(a == b){
            cout << "SMALL" << endl;
            cout << 0 << endl;
            return 0;
        }else{
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    if(n == 2){
        vector<P> v;
        while(true){
            if(a == b){
                break;
            }
            // print_vector(b);
            if(min(b[0], b[1]) <= 0){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            if(b[0] == b[1]){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            if(b[0] > b[1]){
                v.push_back(P('R', 1));
                swap(b[0], b[1]);
                continue;
            }
            if(b[0] < b[1]){
                if(a[0] == b[0] && b[1] >= a[1] && (b[1]-a[1])%a[0] == 0){
                    ll x = (b[1]-a[1])/a[0];
                    v.push_back(P('P', x));
                    break;
                }
                if(a[1] == b[0] && b[1] >= a[0] && (b[1]-a[0])%a[1] == 0){
                    ll x = (b[1]-a[0])/a[1];
                    v.push_back(P('P', x));
                    v.push_back(P('R', 1));
                    break;
                }
                ll x = b[1]/b[0];
                v.push_back(P('P', x));
                b[1] %= b[0];
            }
        }
        ll cnt_p = 0;
        reverse(v.begin(), v.end());
        for(auto [c, x]: v){
            if(c == 'P') cnt_p += x;
        }
        if(cnt_p > 200000){
            cout << "BIG" << endl;
            cout << cnt_p << endl;
            return 0;
        }
        cout << "SMALL" << endl;
        string ans;
        for(auto [c, x]: v){
            for(int i = 0; i < x; i++) ans += c;
        }
        cout << ans.size() << endl;
        cout << ans << endl;
        return 0;
    }
    string ans;
    ll cnt_p = 0;
    while(true){
        auto b_rev = b;
        reverse(b_rev.begin(), b_rev.end());
        if(b == a){
            break;
        }
        if(b_rev == a){
            ans += 'R';
            break;
        }
        ll b_min = *min_element(b.begin(), b.end());
        if(b_min <= 0){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        if(is_sorted(b.begin(), b.end())){
            ans += 'P';
            for(int i = n-1; i >= 1; i--) b[i] = b[i]-b[i-1];
            cnt_p++;
            continue;
        }
        if(is_sorted(b_rev.begin(), b_rev.end())){
            ans += "RP";
            for(int i = n-1; i >= 1; i--) b[i] = b_rev[i]-b_rev[i-1];
            b[0] = b_rev[0];
            cnt_p++;
            continue;
        }
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if(cnt_p > 200000){
        cout << "BIG" << endl;
        cout << cnt_p << endl;
        return 0;
    }
    cout << "SMALL" << endl;
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    cout << ans << endl;
}