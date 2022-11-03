//
//  main.cpp
//  A
//
//  Created by  on 16/7/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int x[maxn];

char s[maxn];

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    scanf("%s",s + 1);
    for(int i = 1;i <= n;i++){
        scanf("%d",x + i);
    }
    int ans = 1e9 + 7;
    bool flag = false;
    for(int i = 1;i < n;i++){
        if(s[i] == 'R' && s[i + 1] == 'L'){
            flag = true;
            ans = min(ans,(x[i + 1] - x[i]) / 2);
        }
    }
    if(flag) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}