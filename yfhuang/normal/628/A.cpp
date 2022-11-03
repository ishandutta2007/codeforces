//
//  main.cpp
//  A
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int n,b,p;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&n,&b,&p);
    int towels;long long bottles=0;
    towels=n*p;
    int m=1;
    while(m<=n) m*=2;
    m/=2;
    while(n>1){
        n=m/2+(n-m);
        bottles+=(2LL*b+1LL)*m/2;
        while(m>n) m/=2;
    }
    cout<<bottles<<' '<<towels<<endl;
    return 0;
}