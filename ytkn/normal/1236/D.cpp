#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

vector<ll> mx[100005], my[100005];
const ll INF = 1e+6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n, m, k;
    cin >> n >> m >> k;
    ll l, r, u, d;
    u = n+1; r = m+1; l = 0,d = 1;
    for(ll i = 0; i < k; i++){
        ll x, y;
        cin >> x >> y;
        mx[x].push_back(y);
        my[y].push_back(x);
    }
    for(ll i = 1; i <= n; i++){
        mx[i].push_back(0);
        mx[i].push_back(m+1);
        sort(mx[i].begin(), mx[i].end());
    }
    for(ll i = 1; i <= m; i++){
        my[i].push_back(0);
        my[i].push_back(n+1);
        sort(my[i].begin(), my[i].end());
    }
    if(mx[1][1] == 2){
        bool flg = true;
        if(k+n <= n*m) false;
        for(int i = 2; i <= n; i++){
            if(mx[i][1] != 2){
                if(mx[i][1] == 1){
                    if(k+i-1 == n*m) flg = true;
                    else flg = false;
                }else{
                    flg = false;
                }
                break;
            }
        }
        if(flg) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    //cout << 'H' << endl;
    ll cur = 1;
    ll cx = 1, cy = 1;
    ll cnt = 1;
    while(true){
        //cout << cur << ' ' << cx << ' ' << cy << endl;
        ll nx;
        ll diff;
        if(cur == 1){
            auto ptr = upper_bound(mx[cx].begin(), mx[cx].end(), cy);
            if(*ptr >= r) nx = r;
            else nx = *ptr;
            r = nx-1;
            diff = r-cy;
            cy = nx-1;
        }
        if(cur == 2){
            auto ptr = upper_bound(my[cy].begin(), my[cy].end(), cx);
            if(*ptr >= u) nx = u;
            else nx = *ptr;
            u = nx-1;
            diff = u-cx;
            cx = nx-1;
        }
        if(cur == 3){
            auto ptr = lower_bound(mx[cx].begin(), mx[cx].end(), cy);
            ptr--;
            if(*ptr <= l) nx = l;
            else nx = *ptr;
            l = nx+1;
            diff = cy-l;
            cy = nx+1;
        }
        if(cur == 4){
            auto ptr = lower_bound(my[cy].begin(), my[cy].end(), cx);
            ptr--;
            if(*ptr <= d) nx = d;
            else nx = *ptr;
            d = nx+1;
            diff = cx-d;
            cx = nx+1;
        }
        //cout << diff << endl;
        if(diff == 0) break;
        cnt += diff;
        cur++;
        if(cur == 5) cur = 1;
    }
    //cout << cnt << endl;
    if(cnt+k == n*m){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}