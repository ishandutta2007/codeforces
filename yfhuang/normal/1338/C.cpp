#include <bits/stdc++.h>
using namespace std;

int t;
typedef long long ll;
typedef pair<ll, int> pi;
ll n;

pi idx(ll n){
    n--;
    ll id1 = n / 3;
    int id2 = n % 3;
    return make_pair(id1 + 1, id2);
}

ll dx[4] = {0, 1, 2, 3};
ll dy[4] = {0, 2, 3, 1}; 

vector<ll> cal(int bit, ll m){
    if(bit == 0){
        return {1, 2, 3};
    }
    m--;
    ll base1 = (1LL << bit);
    ll base2 = (1LL << (bit + 1));
    ll a = base1, b = base2;
    ll base = 1;
    while(m > 0){
        ll id = m % 4;
        a += dx[id] * base;
        b += dy[id] * base;
        m = m / 4;
        base *= 4;
    }
    ll c = a ^ b;
    return {a, b, c};
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        pi id = idx(n);
        int bit = 0;
        ll sum = 1;
        while(sum < id.first){
            bit += 2;
            sum += (1LL << bit);
        }
        sum -= (1LL << bit);
        vector<ll> res = cal(bit, id.first - sum);
        cout << res[id.second] << endl;
    }
    return 0;
}