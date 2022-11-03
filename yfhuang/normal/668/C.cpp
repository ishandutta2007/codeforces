//
//  main.cpp
//  C(div1)
//
//  Created by  on 16/4/25.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 100000 + 5;

double a[maxn];
double b[maxn];

int n;
double suma;
double sumb;

double p_max[maxn];
double p_min[maxn];

void work(int i){
    double y = p_min[i] + p_max[i];
    double x = p_min[i];
    double B = (sumb - suma - y);
    double C = x - sumb * y;
    double delta = sqrt(max((long double) 0,(long double)B * B - 4 * C));
    //if(delta < 0) delta = 0;
    b[i] = (-B + delta) / 2;
    a[i] = y - b[i];
}


int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%lf",p_max + i);
    }
    for(int i = 1;i <= n;i++){
        scanf("%lf",p_min + i);
    }
    suma = 0;
    sumb = 0;
    for(int i = n;i >= 1;i--){
        work(i);
        suma += a[i];
        sumb += b[i];
    }
    for(int i = 1;i <= n;i++)
        printf("%.10lf%c",a[i],i == n ? '\n' :' ');
    for(int i = 1;i <= n;i++)
        printf("%.10lf%c",b[i],i == n ? '\n' : ' ');
    return 0;
}