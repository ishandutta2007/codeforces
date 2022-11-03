//
//  main.cpp
//  A
//
//  Created by  on 8/7/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        if(i == n){
            if(n & 1) printf("I hate it\n");
            else printf("I love it\n");
        }else{
            if(i & 1) printf("I hate that ");
            else printf("I love that ");
        }
    }
    return 0;
}