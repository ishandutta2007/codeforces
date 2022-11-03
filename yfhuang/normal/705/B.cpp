//
//  main.cpp
//  B
//
//  Created by  on 8/7/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;

const int maxn = 100000 + 5;

int a[maxn];

int main(int argc, const char * argv[]) {
    cin >> n;
    long long sum = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        sum += (long long)a[i] - 1;
        if(sum & 1) printf("1\n");
        else printf("2\n");
    }
    return 0;
}