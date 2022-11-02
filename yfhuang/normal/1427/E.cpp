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

ll x;
vector<pair<ll, ll>> ans;
vector<string> op;

void add(ll a, ll b, string o){
    op.push_back(o);
    ans.push_back(mp(a, b));
}

void mul(ll a, ll b){
    vector<ll> tmp;
    tmp.push_back(a);
    ll y = 1;
    for(int i = 0;;i++){
        y *= 2;
        if(y > b){
            break;
        }
        add(tmp.back(), tmp.back(), " + ");
        tmp.push_back(tmp.back() * 2);
    }
    vector<ll> tmp1;
    for(int i = 0;i < tmp.size();i++){
        if(b & (1LL << i)){
            tmp1.push_back(tmp[i]);
        }
    }
    ll now = tmp1[0];
    for(int i = 1;i < tmp1.size();i++){
        add(now, tmp1[i], " + ");
        now += tmp1[i];
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> x;
    int e = 31 - __builtin_clz(x);
    mul(x, 1 << e);
    add((1LL * x) << e, x, " ^ ");
    ll y = ((1LL * x) << e) ^ x; 
    ll a, b;
    for(ll i = 1;;i++){
        ll z = y * i;
        if(z & 1){
            if((z - 1) % x == 0){
                a = (z - 1) / x;
                b = i;
                break;
            }
        }else{
            if((z + 1) % x == 0){
                a = (z + 1) / x;
                b = i;
                break;
            }
        }
    }
    mul(x, a);
    mul(y, b);
    //cout << a << " " << x << " " << b << " " << y << endl;
    x *= a;
    y *= b;
    add(x, y, " ^ ");
    //cout << x << " " << y << endl;
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++){
        cout << ans[i].fi << op[i] << ans[i].se << endl;
    }
    return 0;
}