#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>
#include <random>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
using P = pair<int, int>;

// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    #ifdef DEBUG
    random_device rd;
    mt19937 mt(rd());
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = mt();
    int asked = 0;
    #endif
    vector<int> cnt(n);
    
    auto ask = [&](vector<int> x){
        #ifdef DEBUG
        int ans = 0;
        asked++;
        for(int i : x) {
            ans ^= a[i];
            cnt[i]++;
        }
        return ans;
        #else
        cout << "? ";
        for(int i: x) {
            cnt[i]++;
            cout << i+1 << ' ';
        }
        cout <<  endl;
        int xo; cin >> xo;
        return xo;
        #endif
    };

    auto verify = [&](int x){
        #ifdef DEBUG
        cout << "asked:" << asked << endl;
        int ans = 0;
        for(int i: cnt) assert(i%2 == 1);
        for(int i: a) ans ^= i;
        assert(ans == x);
        #else
        for(int i : cnt) assert(i%2 == 1);
        cout << "! " << x << endl;
        #endif
    };

    if(n%2 == 1 && k%2 == 0){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    vector<int> v(n, 1);
    int sum = n;
    int mx = 1;
    int i = 0;
    while(true){
        if(sum%k == 0 && sum/k >= mx) break;
        v[i] += 2;
        chmax(mx, v[i]);
        sum+=2;
        i = (i+1)%n;
    }

    while(sum){
        priority_queue<P> que;
        for(int i = 0; i < n; i++) que.push(P(v[i], i));
        vector<int> x;
        while(x.size() < k){
            auto [_, i] = que.top(); que.pop();
            x.push_back(i);
            v[i]--;
        }
        ans ^= ask(x);
        sum -= k;
    }

    verify(ans);
}