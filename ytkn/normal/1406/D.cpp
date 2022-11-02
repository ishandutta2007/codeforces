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

int n, q;
ll a[100000];
// d[i] = a[i+1]-a[i]
ll d[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    ll sum_minus = 0, sum_plus = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i != 0) {
            d[i-1] = a[i]-a[i-1];
            if(d[i-1] < 0) sum_minus += (-d[i-1]);
            if(d[i-1] > 0) sum_plus += d[i-1];
        }
    }
    // cout << sum_minus << ' ' << sum_plus << endl;
    ll s = a[0]+sum_plus;
    if(s < 0) cout << (s)/2 << endl;
    else cout << (s+1)/2 << endl;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r; ll x; cin >> l >> r >> x; l--; r--;
        if(l == 0){
            a[0] += x;
        }else{
            if(d[l-1] < 0) sum_minus += d[l-1];
            if(d[l-1] > 0) sum_plus -= d[l-1];
            d[l-1] += x;
            if(d[l-1] < 0) sum_minus -= d[l-1];
            if(d[l-1] > 0) sum_plus += d[l-1];
        }

        if(r == n-1){
            if(n != 1) a[n-1] += x;
        }else{
            if(d[r] < 0) sum_minus += d[r];
            if(d[r] > 0) sum_plus -= d[r];
            d[r] -= x; 
            if(d[r] < 0) sum_minus -= d[r];
            if(d[r] > 0) sum_plus += d[r];
        }
        // cout << a[0] << ' ' << sum_minus << ' ' << sum_plus << endl;
        ll s = a[0]+sum_plus;
        if(s < 0) cout << (s)/2 << endl;
        else cout << (s+1)/2 << endl;
    }
}