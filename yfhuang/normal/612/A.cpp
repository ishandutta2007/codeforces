//
//  main.cpp
//  A
//
//  Created by  on 15/12/26.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=105;

char str[maxn];

int n,p,q;

int main(int argc, const char * argv[]) {
    cin>>n>>p>>q;
    scanf("%s",str+1);
    bool flag=0;
    for(int i=0;i*p<=n;i++){
        if((n-i*p)%q==0){
            flag=1;
            printf("%d\n",i+(n-i*p)/q);
            for(int j=0;j<i;j++){
                for(int k=1;k<=p;k++)
                    printf("%c",str[j*p+k]);
                printf("\n");
            }
            for(int j=0;j<(n-i*p)/q;j++){
                for(int k=1;k<=q;k++)
                    printf("%c",str[i*p+j*q+k]);
                printf("\n");
            }
            break;
        }
    }
    if(!flag) printf("-1\n");
    return 0;
}