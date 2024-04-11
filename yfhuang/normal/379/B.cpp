//
//  main.cpp
//  B
//
//  Created by  on 15/12/30.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=300;

int a[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(i!=n){
            for(int j=1;j<=a[i];j++){
                printf("PRL");
            }
            printf("R");
        }
        if(i==n){
            for(int j=1;j<=a[i];j++){
                printf("PLR");
            }
        }
    }
    return 0;
}