//
//  main.cpp
//  A
//
//  Created by  on 8/4/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    int m,c;
    int c1 = 0,c2 = 0;
    for(int i = 1;i <= n;i++){
        cin >> m >> c;
        if(m > c) c1++;
        else if(m < c) c2++;
    }
    if(c1 > c2) printf("Mishka\n");
    else if(c1 < c2) printf("Chris\n");
    else printf("Friendship is magic!^^\n");
    return 0;
}