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

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    vector<bool> used(n);
    int f;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == -1) f = i;
    }
    if(f == n-1){
        cout << 0 << endl;
        return 0;
    }
    int rem = n-f-1;
    int d = n/2;
    vector<int> v;
    while(rem > 0){
        rem -= d;
        v.push_back(d);
        d /= 2;
    }
    v.pop_back();
    priority_queue<int, vector<int>, greater<int>> que;
    ll ans = a[n-1];
    int cur = n-2;
    for(int x : v){
        for(int i = 0; i < x; i++){
            que.push(a[cur]);
            cur--;
        }
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}