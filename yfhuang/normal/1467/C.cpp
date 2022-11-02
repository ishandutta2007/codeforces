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

int n1, n2, n3;
vector<int> a, b, c;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n1 >> n2 >> n3;
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i = 0;i < n1;i++){
        int x;
        cin >> x;
        sum1 += x;
        a.push_back(x);
    }
    for(int i = 0;i < n2;i++){
        int x;
        cin >> x;
        sum2 += x;
        b.push_back(x);
    }
    for(int i = 0;i < n3;i++){
        int x;
        cin >> x;
        sum3 += x;
        c.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = -1e18;
    ans = max(ans, sum1 + sum2 - sum3);
    ans = max(ans, sum3 + sum2 - sum1);
    ans = max(ans, sum1 + sum3 - sum2);
    ans = max(ans, sum1 + sum2 + sum3 - 2LL * (a[0] + b[0]));
    ans = max(ans, sum1 + sum2 + sum3 - 2LL * (a[0] + c[0]));
    ans = max(ans, sum1 + sum2 + sum3 - 2LL * (c[0] + b[0]));
    cout << ans << endl;
    return 0;
}