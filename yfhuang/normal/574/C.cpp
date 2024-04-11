//
//  main.cpp
//  C
//
//  Created by  on 16/1/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
const int maxn=1e5+16;
int a[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    bool flag=true;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int other=0;
    for(int i=1;i<=n;i++){
        if(i==1){
            while(a[i]%2==0){
                a[i]/=2;
            }
            while(a[i]%3==0){
                a[i]/=3;
            }
            other=a[i];
            //printf("%d ",other);
        }
        else{
            while(a[i]%2==0){
                a[i]/=2;
            }
            while(a[i]%3==0){
                a[i]/=3;
            }
            if(a[i]!=other) {flag=false;break;}
        }
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}