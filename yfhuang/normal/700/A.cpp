//
//  main.cpp
//  A
//
//  Created by  on 7/24/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,l,v1,v2,k;



int main(int argc, const char * argv[]) {
    cin >> n >> l >> v1 >> v2 >> k;
    int ret = (n + k - 1) / k;
    //cout << ret << endl;
    //double x =(v2 * 1.0 / v1 + (ret - 1) * 1.0 * 2 * v2 / (v2 + v1));
    //cout << x << endl;
    double t = 1.0 * l /(v2 * 1.0 / v1 + (ret - 1) * 1.0 * 2 * v2 / (v2 + v1)) /( 1.0 * v1);
    //cout << t << endl;
    double t1 = (1.0 * l - v2 * t) / (1.0 * v1);
    printf("%.10lf\n",t + t1);
    return 0;
}