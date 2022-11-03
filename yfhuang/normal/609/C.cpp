//
//  main.cpp
//  C
//
//  Created by  on 15/12/20.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
const int maxn=1e5+5;

int a[maxn];
int b[maxn];

int main(int argc, const char * argv[]) {
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    int num=ans%n;
    int aver=(ans-num)/n;
    for(int i=1;i<=n-num;i++){
        b[i]=aver;
    }
    for(int i=n;i>=n-num+1;i--){
        b[i]=aver+1;
    }
    sort(a+1,a+1+n);
    int t=0;
    for(int i=1;i<=n;i++){
        t+=abs(a[i]-b[i]);
    }
    t/=2;
    cout<<t<<endl;
    return 0;
}