#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;
ll a, b, c, d;

ll solve(ll x){
    ll times = x / d + 1;
    ll sum = (x / d + 1) * a;
    ll finished;
    if(x < c){
        finished = 0;
    }else{
        finished = (x - c) / d + 1;
    }
    ll left = times - finished;
    ll a1 = x - (x / d) * d;
    sum -= left * a1 * b + left * (left - 1) / 2 * d * b;
    sum -= finished * b * c;
    return sum;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        if(d >= c){
            if(a > b * c){
                cout << -1 << endl;
            }else{
                cout << a << endl;
            }
        }else{
            if(a > b * c){
                cout << -1 << endl;
            }else{
                ll l = 0, r = 1e6 / d;
                while(l < r - 5){
                    ll ml = (l + r) / 2;
                    ll mr = (ml + r) / 2;
                    if(solve(ml * d) <= solve(mr * d)){
                        l = ml;
                    }else{
                        r = mr;
                    }
                }
                ll mx = 0;
                for(ll i = l;i <= r;i++){
                    mx = max(mx, solve(i * d));
                }
                cout << mx << endl;
            }
        }
    }
    return 0;
}