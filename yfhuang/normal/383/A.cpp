//
//  main.cpp
//  383A
//
//  Created by  on 9/7/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 200000 + 5;

int a[maxn];

int cnt[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
    }
    cnt[0] = 0;
    for(int i = 1;i <= n;i++){
        cnt[i] = cnt[i - 1] + (a[i] == 1);
    }
    long long ans = 0;
    for(int i = n;i >= 1;i--){
        if(a[i] == 0){
            ans += cnt[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}