#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
ll n, k;
vector<int> a_even, a_odd;
ll dp1[200000], dp2[100000];


ll calc(int l, int r, int len){
    if(l == k+1 &&  r == k+1){
        if(len == 0) return 1; 
        ll ans = k;
        for(int i = 1; i < len; i++){
            ans *= (k-1);
            ans %= MOD;
        }
        return ans;
    }else if(l == k+1 || r == k+1){
        if(len == 0) return 1; 
        ll ans = k-1;
        for(int i = 1; i < len; i++){
            ans *= (k-1);
            ans %= MOD;
        }
        return ans;
    }
    if(l == r){
        dp1[0] = 1;
        dp2[0] = 0;
    }else{
        dp1[0] = 0;
        dp2[0] = 1;
    }
    for(int i = 1; i <= len; i++){
        dp1[i] = dp2[i-1];
        dp2[i] = (dp1[i-1]*(k-1))%MOD+(dp2[i-1]*(k-2))%MOD;
    }
    return dp2[len];
}

ll calc_array(vector<int> v){
    int l = k+1;
    v.push_back(k+1);
    int cnt = 0;
    ll ans = 1;
    for(int i : v){
        if(i != -1){
            ans *= calc(l, i, cnt);
            ans %= MOD;
            cnt = 0;
            l = i;
        }else{
            cnt++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(i%2 == 0) a_even.push_back(a);
        else a_odd.push_back(a);
    }
    cout << (calc_array(a_even)*calc_array(a_odd))%MOD << endl;
}