//
//  main.cpp
//  B
//
//  Created by  on 15/12/20.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
const int maxm=11;

int ma[maxm];

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    memset(ma,0,sizeof(ma));
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        ma[x]++;
    }
    int ans=0;
    for(int i=1;i<=10;i++){
        for(int j=i+1;j<=10;j++){
            ans+=ma[i]*ma[j];
        }
    }
    cout<<ans<<endl;
    return 0;
}