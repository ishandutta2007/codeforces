//
//  main.cpp
//  E
//
//  Created by  on 16/7/20.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


double p[21];
double ans[21];

double dp[(1 << 20) + 5];
int n,k;
int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        scanf("%lf",p + i);
    }
    dp[0] = 1.0;
    double sp;int m;
    for(int i = 1;i < (1 << n);i++){
        sp = 0;
        m = 0;
        for(int j = 0;j < n;j++){
            if((i & (1 << j)) == 0){
                sp += p[j];
                m++;
            }
        }
        if(n - m > k) continue;
        for(int j = 0;j < n;j++){
            if((i & (1 << j)) != 0){
                if(p[j] < 0.00000001) continue;
                dp[i] += dp[i ^ (1 << j)] * p[j] / (sp + p[j]);
                ans[j] += dp[i ^ (1 << j)] * p[j] / (sp + p[j]);
            }
        }
    }
    for(int i = 0;i < n;i++){
        printf("%.10lf ",ans[i]);
    }
    return 0;
}