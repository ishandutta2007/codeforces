//
//  main.cpp
//  A
//
//  Created by  on 15/12/30.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int a,b,l;

int main(int argc, const char * argv[]) {
    cin>>a>>b;
    int t=0;
    l=0;
    while(a>0){
        l+=a;
        t+=a;
        a=l/b;
        l=l%b;
    }
    printf("%d\n",t);
    return 0;
}