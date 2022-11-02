#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

// int calc(int m){
//     if(m == 0) return 0;
//     if(m == 1) return 1;
//     int l = 1, r = m;
//     while(r-l > 1){
//         int c = (l+r)/2;
//         if((c*(c+1))/2 <= m) l = c;
//         else r = c;
//     }
//     if((l*(l+1))/2 == m) return l;
//     else return -1;
// }

int calc(int m){
    return (m*(m+1))/2;
}

ll min_ll(int n){
    if(n == 0) return 0;
    string s;
    if(n%9 != 0){
        s += ('0'+(n%9));
        n -= (n%9);
    }
    while(n != 0){
        if(n >= 9){
            s += '9';
            n -= 9;
        }
    }
    return stoll(s);
}

void solve(){
    int n, k;
    cin >> n >> k;
    ll ans = -1;
    if(k == 0){
        cout << min_ll(n) << endl;
        return;
    }
    // 
    int m = n-calc(k);
    if(m%(k+1) == 0 && m >= 0){
        int l = m/(k+1);
        int last = 9-k;
        if(last >= l){
            ans = l;
        }else{
            l -= last;
            ans = 10*min_ll(l)+last;
        }
    }
    // 
    for(int i = 1; i <= 18; i++){
        // 
        for(int j = 1; j <= k; j++){
            int last = 9-(k-j);
            
            int m = n-calc(k)+(9*i)*j;
            if(m%(k+1) != 0) continue;
            int l = m/(k+1);
            if(l < (i-1)*9+last) continue;

            string buf;
            buf += '0'+last;
            l -= last;
            for(int k = 1; k < i; k++){
                buf += '9';
                l -= 9;
            }
            if(l >= 9){
                buf += '8';
                l -= 8;
            }
            while(l != 0){
                if(l >= 9){
                    buf += '9';
                    l -= 9;
                }else{
                    buf += '0'+l;
                    l = 0;
                }
            }
            reverse(buf.begin(), buf.end());
            if(ans != -1) ans = min(ans, stoll(buf));
            else ans = stoll(buf);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}