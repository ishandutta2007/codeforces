//
//  main.cpp
//  A
//
//  Created by  on 2017/4/17.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int n,p;
int a[maxn],b[maxn];

bool check(double mid){
    double ans = 0;
    for(int i = 1;i <= n;i++){
        double tmp = max(0.0,a[i] * mid - b[i]);
        ans += tmp / p;
    }
    return ans <= mid;
}

int main(int argc, const char * argv[]) {
    while(cin >> n >> p){
        long long sum = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d%d",a + i,b + i);
            sum += a[i];
        }
        if(sum > 1LL * p){
            double l = 0.0,r = 1e12;
            for(int i = 1;i <= 100;i++){
                double mid = (l + r) / 2;
                if(check(mid)) l = mid;
                else r = mid;
            }
            printf("%.10lf\n",(l + r) / 2);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}