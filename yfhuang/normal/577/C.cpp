//
//  main.cpp
//  C
//
//  Created by  on 16/1/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1005;

bool prime[maxn];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    memset(prime,true,sizeof(prime));
    for(int i=2;i<=n;i++){
        if(prime[i]){
            for(int k=i*2;k<=n;k+=i){
                prime[k]=false;
            }
        }
    }
    vector<int> result;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            int cur=i;
            while(cur<=n){
                result.push_back(cur);
                cur*=i;
            }
        }
    }
    cout<<result.size()<<'\n';
    for(int x:result) cout<<x<<' ';
    return 0;
}