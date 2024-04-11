#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        ll a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        if(a == b){
            cout << 0 << " " << 0 << endl;
        }else{
            ll d = b - a;
            ll x = a / d * d; 
            ll y = (a / d + 1) * d;
            cout << d << " " << min(y - a, a - x) << endl;
        }
    }
    return 0;
}