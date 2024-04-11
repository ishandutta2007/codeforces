//
//  main.cpp
//  A
//
//  Created by  on 15/12/29.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+10;

int a[maxn];
int n;

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l=1,r=1;
    int maxl=1;
    while(l<=n&&r<=n){
        if(r!=n){
            if(a[r+1]>=a[r]){
                r++;
                maxl=max(maxl,r-l+1);}
            else {
                l=r+1;
                r++;
            }
        }
        else {
            maxl=max(maxl,r-l+1);
            break;
        }
    }
    printf("%d\n",maxl);
    return 0;
}