//
//  main.cpp
//  B
//
//  Created by  on 2017/4/17.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1005;

int n;
typedef long long LL;
int x[maxn],y[maxn];

LL sqr(int x){
    return 1LL * x * x;
}

double dis(int i,int j){
    return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

double cal(int i){
    int ax = x[(i + 2) % n] - x[i];
    int bx = x[(i + 1) % n] - x[i];
    int ay = y[(i + 2) % n] - y[i];
    int by = y[(i + 1) % n] - y[i];
    return abs(1LL * ax * by - 1LL * bx * ay) / dis(i,(i + 2) % n);
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d%d",x + i,y + i);
    }
    double mi = 1e18;
    for(int i = 0;i < n;i++){
        mi = min(mi,cal(i));
    }
    printf("%.10lf\n",mi / 2);
    return 0;
}