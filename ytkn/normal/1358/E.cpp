#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int n;
ll a[500005];
ll sum[500005];
ll sum_min[500005];
ll x;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    ll l = (n+1)/2;
    ll r = n-l;
    for(int i = 0; i < l; i++) cin >> a[i];
    cin >> x;
    if(x >= 0){
        ll sum = 0;
        for(int i = 0; i < l; i++) sum += a[i];
        sum += x*r;
        if(sum > 0){
            cout << n << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }
    sum[l-1] = a[l-1];
    for(int i = l-2; i >= 0; i--){
        sum[i] = sum[i+1]+a[i];
    }
    for(int i = l-1; i >= 0; i--){
        sum[i] += x*(r-(l-1-i));
    }
    for(int i = 0; i < l; i++){
        if(i == 0) sum_min[i] = sum[i];
        else sum_min[i] = min(sum_min[i-1], sum[i]);
        // cout << sum[i] << ' ';
    }
    // cout << endl;
    for(ll i = 1; i <= l; i++){
        ll th = -(i-1)*x;
        // cout << sum_min[l-i] << ' ' << th << endl;
        if(sum_min[l-i] > th){
            cout << i+r << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}