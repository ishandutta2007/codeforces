//
//  main.cpp
//  A
//
//  Created by  on 16/1/23.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    int x;
    cin>>x;
    if(x%5==0) printf("%d\n",x/5);
    else printf("%d\n",x/5+1);
    return 0;
}