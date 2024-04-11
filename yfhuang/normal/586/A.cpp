//
//  main.cpp
//  A
//
//  Created by  on 16/1/28.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int a[105];

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int f1=-1,l1=101;
    for(int i=0;i<n;i++){
        if(a[i]==1) {
            f1=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==1){
            l1=i;
            break;
        }
    }
    if(f1==-1) {printf("0\n"); return 0;}
    int cnt=0;
    for(int i=f1+1;i<=l1;i++){
        if(a[i]==0&&a[i-1]==0){
            cnt+=1;
            while(a[i]==0&&a[i-1]==0){
                i++;
                cnt++;
            }
        }
    }
    //printf("%d",cnt);
    printf("%d\n",l1-f1+1-cnt);
    return 0;
}