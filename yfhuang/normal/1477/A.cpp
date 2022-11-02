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

int t;
int n;
ll k;
const int maxn = 2e5 + 5;
ll x[maxn];

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        sort(x + 1, x + 1 + n);
        ll d = x[2] - x[1];
        for(int i = 2;i < n;i++){
            d = gcd(d, x[i + 1] - x[i]);
        }
        bool flag = false;
        for(int i = 1;i <= n;i++){
            if(abs(x[i] - k) % d == 0){
                flag = true;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}