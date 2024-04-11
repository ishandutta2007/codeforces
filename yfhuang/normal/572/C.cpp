//
//  main.cpp
//  C
//
//  Created by  on 16/2/4.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b,c,l;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d%d",&a,&b,&c,&l);
    long long ans=0;
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    if(b<c) swap(b,c);
    ans=(long long)(l+3)*(l+2)*(l+1)/6;
    for(int i=l;i>=0;i--){
        if(a+i>=b+c){
            int ma=min(a+i-b-c,l-i);
            ans-=(long long)(1+(ma+1))*(ma+1)/2;
        }
    }
    for(int i=l;i>=0;i--){
        if(b+i>=(a+c)){
            int ma=min(b+i-a-c,l-i);
            ans-=(long long)(1+(ma+1))*(ma+1)/2;
        }
    }
    for(int i=l;i>=0;i--){
        if(c+i>=(a+b)){
            int ma=min(c+i-a-b,l-i);
            ans-=(long long)(1+(ma+1))*(ma+1)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}