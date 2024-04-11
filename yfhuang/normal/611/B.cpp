//
//  main.cpp
//  B
//
//  Created by  on 15/12/30.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long a,b;

int main(int argc, const char * argv[]) {
    cin>>a>>b;
    int cnt=0;
    for(long long i=2;i<=b;i*=2){
        if(i*2-2>=a){
            for(long long j=1;j<i;j*=2){
                if(i*2-1-j>=a&&i*2-1-j<=b) cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}