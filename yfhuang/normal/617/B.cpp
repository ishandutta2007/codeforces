//
//  main.cpp
//  B
//
//  Created by  on 16/1/23.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn=105;

int a[maxn];

int b[100];

int n;

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int f1=0,l1=n+1;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            f1=i;break;
        }
    }
    for(int i=n;i>=1;i--){
        if(a[i]==1){
            l1=i;
            break;
        }
    }
    if(f1==0){
        printf("0\n") ;return 0;
    }
    long long ans=1;
    int num=0;
    for(int i=f1+1;i<=l1;i++){
        if(a[i]==0) num++;
        else{
            ans*=num+1;
            num=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}