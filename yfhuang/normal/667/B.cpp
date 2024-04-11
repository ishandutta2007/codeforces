//
//  main.cpp
//  B
//
//  Created by  on 16/4/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

int a[maxn];

int main(int argc, const char * argv[]) {
    long long sum = 0;
    int n;
    cin >> n;
    int maxa = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        sum += (long long)a[i];
        maxa = max(a[i],maxa);
    }
    long long rest = sum - (long long)maxa;
    int ans;
    //cout << maxa << endl;
    //cout << rest << endl;
    if(rest >= (long long)maxa) ans = 1;
    else ans = maxa - (int)rest + 1;
    cout << ans << endl;
    return 0;
}