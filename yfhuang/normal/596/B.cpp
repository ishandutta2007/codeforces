//
//  main.cpp
//  B
//
//  Created by  on 15/11/16.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=200000+10;
int n;
int b[maxn];

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    long long ans;
    ans+=abs(b[1]-0);
    for(int i=2;i<=n;i++){
        ans+=abs(b[i]-b[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}