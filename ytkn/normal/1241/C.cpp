#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
ll p[200000];

template <typename T>
T gcd(T a, T b){
    if(a < b) swap(a, b);
    while(b != 0){
        T tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

template <typename T>
T lcm(T a, T b){
    return (a*b)/gcd<T>(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for(int dummy = 0; dummy < q; dummy++){
        ll n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i] /= 100;
        }
        sort(p, p+n, greater<ll>());
        ll x, y, a, b, k;
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        ll lc = lcm(a, b);
        if(x < y){
            swap(x, y);
            swap(a, b);
        }
        ll sum = 0;
        int cnt = 1;
        int idx = 0;        
        while(cnt*lc <= n && idx < n){
            cnt++;
            sum += p[idx]*(x+y);
            idx++;
        }
        cnt = 1;
        while(cnt*a <= n && idx < n){
            if((cnt*a)%lc != 0){
                sum += p[idx]*(x);
                idx++;
            }
            cnt++;
        }
        cnt = 1;
        while(cnt*b <= n && idx < n){
            if((cnt*b)%lc != 0){
                sum += p[idx]*(y);
                idx++;
            }
            cnt++;
        }
        if(sum < k){
            cout << -1 << endl;
            continue;
        }
        ll l = 0, r = n;
        while(r-l > 1){
            ll c = (l+r)/2;
            cnt = 1;
            idx = 0;
            sum = 0;
            while(cnt*lc <= c && idx < n){
                cnt++;
                sum += p[idx]*(x+y);
                idx++;
            }
           // cout << sum << endl;
            cnt = 1;
            while(cnt*a <= c && idx < n){
                if((cnt*a)%lc != 0){
                    sum += p[idx]*(x);
                    idx++;
                }
                cnt++;
            }
            //cout << sum << endl;
            cnt = 1;
            while(cnt*b <= c && idx < n){
                if((cnt*b)%lc != 0){
                    sum += p[idx]*(y);
                    idx++;
                }
                cnt++;
            }
            //cout << sum << endl;
            if(sum < k){
                l = c;
            }else{
                r = c;
            }
            //cout << c << ' ' << sum << ' ' << idx <<  endl;
        }
        cout << r << endl;
    }
}