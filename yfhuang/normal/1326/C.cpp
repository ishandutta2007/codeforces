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
#include <random>
#include <chrono>
using namespace std;

int k, n;
const int maxn = 2e5 + 5;

typedef pair<int, int> pii;

int a[maxn];
pii p[maxn];

const int mod = 998244353;

int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        p[i] = make_pair(a[i], i);
    }
    sort(p + 1, p + 1 + n);
    vector<int> b;
    long long res = 0;
    for(int i = n;i > n - k;i--){
        res += p[i].first;
        b.push_back(p[i].second);
    }
    sort(b.begin(), b.end());
    long long ans = 1;
    for(int i = 0;i < b.size() - 1;i++){
        //cout << b[i + 1] << " " << b[i] << endl;
        int len = b[i + 1] - b[i];
        ans = ans * len % mod;
    }
    cout << res << " " << ans << endl;
    return 0;
}