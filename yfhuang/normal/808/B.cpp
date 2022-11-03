//
//  main.cpp
//  B
//
//  Created by  on 2017/5/15.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2e5 + 5;

int n,k;

int a[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
    }
    long long sum = 0;
    double ans = 0;
    for(int i = 1;i <= k;i++){
        sum += a[i];
    }
    ans += sum * 1.0 / (n - k + 1);
    for(int i = k + 1;i <= n;i++){
        sum += a[i] - a[i - k];
        ans += sum * 1.0 / (n - k + 1);
    }
    printf("%.10lf\n",ans);
    return 0;
}