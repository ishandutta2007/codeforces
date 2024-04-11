#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>
#include <tuple>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
using T = tuple<int, int, int>;

vector<int> get_vector(int n){
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    return v;
}

void verify(vector<int> a, vector<T> ans){
    int n = a.size();
    for(auto [i, j, k]: ans){
        int x = a[i]^a[j]^a[k];
        a[i] = x;
        a[j] = x;
        a[k] = x;
    }
    for(int i = 1; i < n; i++) assert(a[i] == a[i-1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    auto a = get_vector(n);
    vector<T> ans;
    if(n%2 == 0){
        if(accumulate(a.begin(), a.end(), 0, [](int x, int y){ return x^y; }) != 0){
            cout << "NO" << endl;
            return 0;
        }
        for(int i = 1; i+2 < n; i += 2){
            ans.push_back(T(i, i+1, i+2));
        }
        for(int i = n-3; i-2 >= 1; i -= 2){
            ans.push_back(T(i, i-1, i-2));
        }
    }else{
        for(int i = 0; i+2 < n; i += 2){
            ans.push_back(T(i, i+1, i+2));
        }
        for(int i = n-3; i-2 >= 0; i -= 2){
            ans.push_back(T(i, i-1, i-2));
        }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto [i, j, k]: ans) cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
    // verify(a, ans);
}