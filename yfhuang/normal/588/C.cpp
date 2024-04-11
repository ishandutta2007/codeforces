//
//  main.cpp
//  C
//
//  Created by  on 15/12/12.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxw=1e6+10;

int a[maxw];
int n;

int main(int argc, const char * argv[]) {
    cin>>n;
    memset(a,0,sizeof(a));
    int maxx=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        maxx=max(maxx,x);
        a[x]++;
    }
    int sum=0;
    for(int i=0;i<=maxx+100;i++){
        if(a[i]<2){
            sum+=a[i];
        }
        else{
            a[i+1]+=a[i]/2;
            sum+=(a[i]%2);
        }
    }
    printf("%d\n",sum);
    return 0;
}