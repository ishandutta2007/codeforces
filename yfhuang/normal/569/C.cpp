//
//  main.cpp
//  C
//
//  Created by  on 16/3/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int palin(int x){
    int t=0,y=x;
    for(;y;y/=10){
        t=t*10+y%10;
    }
    return t==x;
}

bool is_prime[2000005];

int main(int argc, const char * argv[]) {
    int p,q;
    scanf("%d%d",&p,&q);
    memset(is_prime,true,sizeof(is_prime));
    
    is_prime[1]=false;
    
    for(int i=2;i<=2000000;i++){
        if(is_prime[i])
        for(int j=2*i;j<=2000000;j+=i){
            is_prime[j]=false;
        }
    }
    int cp=0,cq=0;
    int i;
    int ans=0;
    for( i=1;i<=2000000;i++){
        cp+=(is_prime[i]==true);
        cq+=palin(i);
        if(cp*q<=p*cq) ans=max(ans,i);
    }
    cout<<ans<<endl;
    return 0;
}