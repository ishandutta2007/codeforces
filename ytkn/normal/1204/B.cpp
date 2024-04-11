#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    ll m = 0;
    for(int i = 0; i < n; i++){
        if(i <= n-l){
            m += 1;
        }
        if(i > n-l){
            ll tmp = (ll)1<<(i+l-n);
            m += tmp;
        }
    }
    ll M = 0;
    for(int i = 0; i < n; i++){
        if(i < r){
            ll tmp = (ll)1<<i;
            M += tmp;
        }else{
            ll tmp = (ll)1<<(r-1);
            M += tmp;
        }
    }
    cout << m << ' ' << M << endl;
}