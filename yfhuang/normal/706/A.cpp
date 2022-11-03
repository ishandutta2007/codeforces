//
//  main.cpp
//  A
//
//  Created by  on 8/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int n;
int a,b;
int x,y,v;

int main(int argc, const char * argv[]) {
    cin >> a >> b;
    cin >> n;
    double mint = 1e9;
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d",&x,&y,&v);
        double l = sqrt(1.0 * (x - a) * (x - a) + 1.0 * (y - b) * (y - b));
        mint = min(mint,l / (1.0 * v));
    }
    printf("%.10lf\n",mint);
    return 0;
}