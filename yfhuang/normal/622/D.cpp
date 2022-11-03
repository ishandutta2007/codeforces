//
//  main.cpp
//  D
//
//  Created by  on 16/2/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn=5e5+5;

int n;

int a[maxn*2];

int main(int argc, const char * argv[]) {
    cin>>n;
    if(n&1){
        for(int i=1;i<n;i++){
            if(i&1){
                a[(i+1)/2]=a[n+1-(i+1)/2]=i;
            }else{
                a[i/2+n]=a[i/2+n-i+n]=i;
            }
        }
        a[(n+1)/2]=a[2*n]=n;
    }else{
        for(int i=1;i<n;i++){
            if(i&1){
                a[(i+1)/2]=a[n+1-(i+1)/2]=i;
            }else{
                a[i/2+n]=a[i/2+n-i+n]=i;
            }
        }
        a[2*n]=a[n+n/2]=n;
    }
    for(int i=1;i<=2*n;i++){
        printf("%d%c",a[i],i==2*n ? '\n':' ');
    }
    return 0;
}