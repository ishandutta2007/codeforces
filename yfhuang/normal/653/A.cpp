//
//  main.cpp
//  A
//
//  Created by  on 16/3/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=55;

int a[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bool flag=false;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[i]!=a[j]&&a[i]!=a[k]&&a[j]!=a[k]&&abs(a[i]-a[j])<=2&&abs(a[i]-a[k])<=2&&abs(a[k]-a[j])<=2) flag=true;
            }
        }
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}