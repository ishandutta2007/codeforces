//
//  main.cpp
//  E
//
//  Created by  on 10/18/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 5e5 + 5;

double a[maxn];
double ans[maxn];

char s[maxn];

int n;

int main(int argc, const char * argv[]) {
    scanf("%s",s + 1);
    n = (int)strlen(s + 1);
    a[0] = 0.0;
    for(int i = 1;i < maxn;i++){
        a[i] = a[i - 1] + 1.0 / (1.0 * i);
    }
    ans[0] = a[0];
    for(int i = 1;i < maxn;i++){
        ans[i] = ans[i - 1] + a[i];
    }
    double anss = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'Y' || s[i] == 'U'){
            anss += ans[n] - ans[n - i] - ans[i - 1];
        }
    }
    printf("%.10lf\n",anss);
    return 0;
}