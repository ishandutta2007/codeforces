#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int n;
typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 1 << " " << 1 << endl;
        cout << -a[1] << endl;
        a[1] = 0;
        cout << 1 << " " << 1 << endl;
        cout << -a[1] << endl;
        a[1] = 0;
        cout << 1 << " " << 1 << endl;
        cout << -a[1] << endl;
        a[1] = 0;
        return 0;
    }
    cout << 1 << " " << 1 << endl;
    cout << -a[1] << endl;
    a[1] = 0;
    cout << 1 << " " << n << endl;
    for(int i = 1;i <= n;i++){
        ll d = (a[i] % (n - 1) + (n - 1)) % (n - 1);
        ll delta = ((n - 1) - d) % (n - 1);
        ll add = delta * n;
        cout << add << ((i == n ? '\n' : ' '));
        a[i] += add;
    } 
    cout << 2 << " " << n << endl;
    for(int i = 2;i <= n;i++){
        cout << -a[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}