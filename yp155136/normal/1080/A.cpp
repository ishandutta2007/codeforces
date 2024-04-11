#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x,ll y) {
    return (x+y-1)/y;
}

int main () {
    ll n,k;
    cin >> n >> k;
    //swap(k,n);
    ll x=2*n,y=5*n,z=8*n;
    cout << f(x,k) + f(y,k) + f(z,k) << endl;
}