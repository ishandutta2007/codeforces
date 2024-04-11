#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a+c <= b){
            cout << 0 << endl;
        }else{
            ll m = max((a+b+c)/2+1, a);
            //cout << m << ' ' << a+c << endl;
            cout << a+c-m+1 << endl;
        }
    }
}