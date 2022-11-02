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

const int maxn = 2e5 + 5;

int cnt1[maxn], cnt2[maxn];
int t;
int a, b, k;
int x[maxn], y[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> k;
        for(int i = 1;i <= max(a, b);i++){
            cnt1[i] = 0;
            cnt2[i] = 0;
        }
        ll ans = 0;
        for(int i = 1;i <= k;i++){
            cin >> x[i];
        }
        for(int i = 1;i <= k;i++){
            cin >> y[i];
        }
        for(int i = 1;i <= k;i++){
            ans += (i - 1) - (cnt1[x[i]] + cnt2[y[i]]);
            cnt1[x[i]]++;
            cnt2[y[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}