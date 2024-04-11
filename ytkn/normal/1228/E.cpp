#include <iostream>

using namespace std;

typedef long long ll;
const long MOD = 1000000007;

int n;
ll k;

ll pow[70000], pow_[700000];
ll comb[300][300];

void init(){
    pow[0] = 1;
    pow_[0] = 1;
    for(int i = 1; i < 70000; i++){
        pow[i] = pow[i-1]*k;
        pow[i] %= MOD;
        pow_[i] = pow_[i-1]*(k-1);
        pow_[i] %= MOD;
    }
    for(int i = 0; i < 300; i++){
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    for(int i = 1; i < 300; i++){
        for(int j = 1; j < i; j++){
            comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
            comb[i][j] %= MOD;
        }
    }

}

ll calc(int i, int j){
    ll c = (comb[n][i]*comb[n][j])%MOD;
    ll p = (pow[n*n-((i+j)*n-i*j)]*pow_[((i+j)*n-i*j)])%MOD;
    return (c*p)%MOD;
}

int main(){
    cin >> n >> k;
    init();
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if((i+j)%2 == 0){
                ans += calc(i, j);
            }else{
                ans -= calc(i, j);
            }
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
}