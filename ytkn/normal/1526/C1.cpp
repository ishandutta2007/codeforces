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

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll pos_sum = 0;
    int pos_cnt = 0;
    ll neg_sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            pos_sum += a[i];
            pos_cnt++;
        }else{
            if(neg_sum+pos_sum+a[i] >= 0){
                que.push(a[i]);
                neg_sum += a[i];
            }else{
                if(!que.empty()){
                    ll x = que.top(); que.pop();
                    ll y = max(a[i], x);
                    neg_sum += (y-x);
                    que.push(y);
                }
            }
        }
    }
    cout << pos_cnt+que.size() << endl;
}