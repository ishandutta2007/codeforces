//
//  main.cpp
//  B
//
//  Created by  on 16/6/2.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int main(int argc, const char * argv[]) {
    int n, h, k;
    scanf("%d%d%d", &n, &h, &k);
    long long ans = 0;
    int remain = 0;
    while(n--) {
        int x;
        scanf("%d", &x);
        if(remain + x <= h) remain += x;
        else {
            int tmp = remain / k;
            remain -= tmp * k;
            ans += tmp;
            if(remain + x > h) {
                ++ans;
                remain = 0;
            }
            remain += x;
        }
    }
    ans += (remain + k - 1) / k;
    printf("%I64d\n", ans);
    return 0;
}