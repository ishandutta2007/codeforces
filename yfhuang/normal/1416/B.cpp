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
const int maxn = 1e4 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll sum = 0;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n != 0){
            cout << -1 << endl;
            continue;
        }else{
            cout << 3 * n - 3 << endl;
            for(int i = 2;i <= n;i++){
                cout << 1 << " " << i << " " << (i - a[i] % i) % i << endl;
                cout << i << " " << 1 << " " << (a[i] + i - 1) / i << endl;
            }
            for(int i = 2;i <= n;i++){
                cout << 1 << " " << i << " " << sum / n << endl;
            }
        }
    }
    return 0;
}