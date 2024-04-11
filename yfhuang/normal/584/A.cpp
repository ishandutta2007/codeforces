//
//  main.cpp
//  A
//
//  Created by  on 15/12/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,t;
    cin>>n>>t;
    if(n==1&&t==10) printf("-1\n");
    else{
        if(t<10)
        {printf("%d",t);
        for(int i=1;i<n;i++)
            printf("0");
            printf("\n");}
        else if(t==10){
            printf("1");
            for(int i=1;i<n;i++)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}