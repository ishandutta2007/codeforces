//
//  main.cpp
//  A
//
//  Created by  on 10/11/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

const int maxn = 1005;
int a[maxn],b[maxn];
char sa[maxn],sb[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    scanf("%s%s",sa + 1,sb + 1);
    for(int i = 1;i <= n;i++){
        a[i] = sa[i] - '0';
        b[i] = sb[i] - '0';
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans += min(abs(a[i] - b[i]),min(a[i] + 10 - b[i],b[i] + 10 - a[i]));
    }
    cout << ans << endl;
    return 0;
}