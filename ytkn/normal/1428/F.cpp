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

ll n;
string s;

void input(){
    cin >> n >> s;
}

ll calc(ll m){
    return (m*(m+1))/2;
}

int cnt_len(int len){
    int ans = 0;
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            int cnt = 0;
            bool ok = false;
            for(int i = l; i <= r; i++){
                if(s[i] == '1') {
                    cnt++;
                    if(cnt >= len) ok = true;
                }else{
                    cnt = 0;
                }
            }
            if(ok) ans++;
        }
    }
    return ans;
}

void solve(){
    vector<ll> v;
    if(s[0] == '1') v.push_back(0);
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            v.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    v.push_back(cnt);
    if(s[n-1] == '1') v.push_back(0);
    ll ans = 0;
    for(ll l = 1; l <= n; l++){
        ans += (n*(n+1))/2;
        if(v.size() != 1){
            for(int i = 0; i < v.size(); i += 2){
                if(i == 0){
                    ans -= v[i]*(l-1)+calc(v[i]);
                }else if(i+1 == v.size()){
                    ans -= v[i]*(l-1)+calc(v[i]);
                }else{
                    ans -= 2*v[i]*(l-1)+calc(v[i]);
                    ans -= (l-1)*(l-1);
                }
            }
        }else{
            ans -= calc(n);
        }
        for(int i = 1; i < v.size(); i += 2){
            ans -= ((l-1)*(v[i]+v[i]-l+2))/2;
        }
        vector<int> buf;
        // l
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            if(i%2 == 1){
                if(v[i] >= l+1){
                    buf.push_back(sum);
                    buf.push_back(v[i]);
                    sum = 0;
                }else{
                    sum += v[i];
                }
            }else{
                sum += v[i];
            }
        }
        buf.push_back(sum);
        v.clear();
        for(ll i : buf){
            v.push_back(i);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}