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
int n, m;
const int maxn = 3e5 + 5;
int k[maxn];
int c[maxn];
ll pre[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            cin >> k[i];
        }
        for(int i = 1;i <= m;i++){
            cin >> c[i];
        }
        sort(k + 1, k + 1 + n);
        pre[0] = 0;
        for(int i = 1;i <= n;i++){
            pre[i] = pre[i - 1] + c[k[i]];
        }
        ll ans = pre[n];
        ll sum = 0;
        for(int i = n;i >= 1;i--){
            if(n + 1 - i > m)
                break;
            sum += c[n + 1 - i];
            ans = min(ans, pre[i - 1] + sum);
        }
        cout << ans << endl;
    }
    return 0;
}