#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;
const int maxn = 3e5 + 5;

typedef long long LL;

LL p, k;
LL a[maxn];
map<LL, int> mp;

int main(){
    cin >> n >> p >> k;
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
        LL tmp = (a[i] * a[i] % p * a[i] % p * a[i] % p - a[i] * k % p + p) % p;
        ans += mp[tmp];
        mp[tmp]++;
    }
    cout << ans << endl;
    return 0;
}