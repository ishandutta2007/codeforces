//
//  main.cpp
//  A
//
//  Created by  on 15/12/30.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int num;
char a[5];
char b[10];

int main(int argc, const char * argv[]) {
    cin>>num>>a>>b;
    if(b[0]=='m'){
        if(num<=29){
            printf("12\n");
        }
        else if(num==30) printf("11\n");
        else printf("7\n");
    }
    else{
        if(num==5||num==6){
            printf("53\n");
        }
        else printf("52\n");
    }
    return 0;
}