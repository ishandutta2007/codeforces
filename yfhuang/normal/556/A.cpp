//
//  main.cpp
//  A
//
//  Created by  on 16/1/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
const int maxn=2e5+5;

char str[maxn];

int main(int argc, const char * argv[]) {
    cin>>n;
    scanf("%s",str);
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(str[i]=='1') cnt1++;
    }
    printf("%d",abs(n-cnt1*2));
    return 0;
}