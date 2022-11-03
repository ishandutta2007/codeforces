//
//  main.cpp
//  B
//
//  Created by  on 10/11/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,k,p,x,y;

const int maxn = 1005;
int a[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> k >> p >> x >> y;
    int n1 = 0,n2 = 0;
    for(int i = 1;i <= k;i++){
        scanf("%d",a + i);
        if(a[i] >= y) n2++;
        else n1++;
    }
    int half = n / 2;
    if(n1 > half){
        puts("-1");
        return 0;
    }
    int now = k;
    for(int i = n2 + 1;i <= half + 1;i++){
        a[++now] = y;
    }
    for(int i = now + 1;i <= n;i++){
        a[i] = 1;
    }
    int sum = 0;
    for(int i = 1;i <= n;i++){
        sum += a[i];
    }
    if(sum > x){
        puts("-1");
        return 0;
    }
    for(int i = k + 1;i <= n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}