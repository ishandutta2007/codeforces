//
//  main.cpp
//  C
//
//  Created by  on 16/2/14.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=5e6+5;

bool dp[maxn];

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    int ans=0,x=0,y=0,z=0;
    while(true){
        if(max(n-x,0)+max(m-y,0)<=z) break;
        ans++;
        if(ans%6==0) z++;
        else if(ans%2==0) x++;
        else if(ans%3==0) y++;
    }
    printf("%d\n",ans);
    return 0;
}