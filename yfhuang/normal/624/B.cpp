//
//  main.cpp
//  B
//
//  Created by  on 16/2/5.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n;

int a[30];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    long long ans=0;
    int crt=a[n];
    ans+=a[n];
    for(int i=n-1;i>=1;i--){
        if(a[i]==crt){
            crt--;
            ans+=(long long)crt;
        }else if(crt>a[i]){
            crt=a[i];
            ans+=(long long)crt;
        }else{
            if(crt>0){
                crt--;
                ans+=(long long)crt;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}