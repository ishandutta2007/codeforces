//
//  main.cpp
//  B
//
//  Created by  on 10/9/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int n;
const int maxn = 2e5 + 5;

int b[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    int maxx = 0;
    int minx = 1e9 + 5;
    for(int i = 1;i <= n;i++){
        scanf("%d",b + i);
        maxx = max(b[i],maxx);
        minx = min(b[i],minx);
    }
    int num1 = 0;
    int num2 = 0;
    for(int i = 1;i <= n;i++){
        if(b[i] == maxx) num1++;
        if(b[i] == minx) num2++;
    }
    long long ans = 0;
    if(maxx > minx) ans = (long long) num1 * (long long) num2;
    else if(maxx == minx) ans = (long long) n * (long long)(n - 1) / 2;
    cout << maxx - minx << " " << ans << endl;
    return 0;
}