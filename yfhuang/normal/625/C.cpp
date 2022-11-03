//
//  main.cpp
//  C
//
//  Created by  on 16/2/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k;
    cin>>n>>k;
    int a[505][505];
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<k;j++){
            cnt++;
            a[i][j]=cnt;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=k;j<=n;j++){
            cnt++;
            a[i][j]=cnt;
        }
    }
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=(long long)a[i][k];
    }
    cout<<sum<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("%d\n",a[i][n]);
    }
    return 0;
}