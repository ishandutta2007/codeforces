//
//  main.cpp
//  C
//
//  Created by  on 9/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;


typedef long long ll;
const ll mod = 10007;
ll a[maxn];

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ans = (ans + a[i] * a[n + 1 - i]) % mod;
    }
    cout << ans << endl;
    return 0;
}