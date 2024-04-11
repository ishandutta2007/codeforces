#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    while(b > 0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(){
    ll n, m;
    int q;
    cin >> n >> m >> q;
    ll d = gcd(m ,n);
    ll N = n/d;
    ll M = m/d;
    for(int i = 0; i < q; i++){
        ll sx, sy, ex, ey;
        ll is, ie;
        cin >> sx >> sy >> ex >> ey;
        if(sx == 1){
            is = (sy-1)/N;
        }else{
            is = (sy-1)/M;
        }
        if(ex == 1){
            ie = (ey-1)/N;
        }else{
            ie = (ey-1)/M;
        }
        if(is == ie){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}