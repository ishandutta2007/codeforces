//
//  main.cpp
//  F
//
//  Created by  on 16/1/2.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1e5+16;

char str[maxn];

int n,m;

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    scanf("%s",str+1);
    long long ans=n*m-n;
    for(int i=2;i<=n;i++)
        if(str[i]!=str[i-1])
            ans+=n*m-n;
    long long cur=1;
    for(int i=2;i<=n;i++){
        if(cur==1){
            if(str[i]==str[i-1])
                continue;
            else cur++;
        }
        else{
            if(str[i]==str[i-2])
                cur++;
            else{
                ans-=(cur*(cur-1))/2;
                if(str[i]==str[i-1])
                    cur=1;
                else cur=2;
            }
        }
    }
    ans-=(cur*(cur-1))/2;
    cout<<ans<<endl;
    return 0;
}