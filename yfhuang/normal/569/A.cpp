//
//  main.cpp
//  A
//
//  Created by  on 16/3/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int s,t,q;

int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&t,&s,&q);
    int i;
    int now=0;
    for(i=1;;i++){
        while(now<s){
            s+=q-1;
            now+=q;
        }
        now=0;
        if(s>=t) break;
    }
    cout<<i<<endl;
    return 0;
}