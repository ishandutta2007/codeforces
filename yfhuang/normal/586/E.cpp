//
//  main.cpp
//  585C
//
//  Created by  on 15/12/8.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main(int argc, const char * argv[]) {
    LL x,y;
    //printf("%d",gcd(2,4));
    cin>>x>>y;
    if(gcd(x,y)>1) printf("Impossible\n");
    else{
        while(x&&y){
            if(x>y) {cout<<(x-1)/y<<'A';x%=y;}
            else {cout<<(y-1)/x<<'B';y%=x;}
        }
        printf("\n");
    }
    return 0;
}