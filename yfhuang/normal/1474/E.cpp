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

int T;
int n;
const int maxn = 1e5 + 5;
int p[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        ll ans = 0;
        vector<int> left, right;
        left.push_back(1);
        vector<pi> op;
        for(int i = (n + 1) / 2 + 1;i < n;i++){
            left.push_back(i);  
            ans += 1LL * (i - 1) * (i - 1); 
            op.push_back(mp(i, 1));
        }
        right.push_back(n);
        for(int i = (n + 1) / 2;i > 1;i--){
            right.push_back(i);
            ans += 1LL * (n - i) * (n - i);
            op.push_back(mp(i, n));
        }
        op.push_back(mp(1, n));
        ans += 1LL * (n - 1) * (n - 1);
        vector<int> a;
        for(auto v : left){
            a.push_back(v);
        }
        for(auto v : right){
            a.push_back(v);
        }
        cout << ans << endl;
        for(int i = 0;i < n;i++){
            p[a[i]] = a[(i + 1) % n];
        }
        for(int i = 1;i <= n;i++){
            cout << p[i] << ((i == n) ? '\n' : ' ');
        }
        cout << op.size() << endl;
        for(int i = 0;i < n - 1;i++){
            cout << op[i].fi << " " << op[i].se << endl;
        }
    }
    return 0;
}