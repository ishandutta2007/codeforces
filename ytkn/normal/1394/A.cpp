#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

int n, d, m;
ll a[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> d >> m;
    vector<ll> smaller, larger;
    vector<ll> cumsum_smaller, cumsum_larger;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= m) smaller.push_back(a[i]);
        else larger.push_back(a[i]);
    }
    sort(smaller.begin(), smaller.end(), greater<ll>());
    sort(larger.begin(), larger.end(), greater<ll>());
    cumsum_smaller.push_back(0);
    ll sum = 0;
    for(ll x : smaller){
        sum += x; cumsum_smaller.push_back(sum);
    }
    cumsum_larger.push_back(0);
    sum = 0;
    for(ll x : larger){
        sum += x; cumsum_larger.push_back(sum);
    }
    ll ans = cumsum_smaller[cumsum_smaller.size()-1];
    // cout << ans << endl;
    for(int i = 1; i <= larger.size(); i++){
        int rem = n-(1+(i-1)*(d+1));
        // cout << i << ' ' << rem << endl;
        if(rem < 0) break;
        if(rem >= cumsum_smaller.size()) {
            ans = max(ans, cumsum_larger[i]+cumsum_smaller[cumsum_smaller.size()-1]);
        }else{
            ans = max(ans, cumsum_larger[i]+cumsum_smaller[rem]);
        }
        // cout << ans << ' ' << cumsum_larger[i] << ' ' << cumsum_smaller[rem] << endl;
    }
    cout << ans << endl;
}