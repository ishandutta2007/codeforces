//
//  main.cpp
//  A
//
//  Created by  on 16/1/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n;
const int maxn =105;

int a[maxn];

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int minc=0;
    int cnt;
    for(int i=0;i<=1000;i++){
        cnt=0;
        for(int j=2;j<=n;j++){
            if(a[j]>=a[1]+i){
                cnt+=a[j]-(a[1]+i-1);
            }
        }
        if(cnt<=i) {minc=i;break;}
    }
    printf("%d\n",minc);
    return 0;
}