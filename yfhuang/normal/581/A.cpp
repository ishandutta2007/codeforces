//
//  main.cpp
//  A
//
//  Created by  on 15/12/27.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int a,b;

int main(int argc, const char * argv[]) {
    cin>>a>>b;
    if(a<b) swap(a,b);
    printf("%d %d\n",b,(a-b)/2);
    return 0;
}