//
//  main.cpp
//  C
//
//  Created by  on 15/12/27.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int k;
char s[1<<9][(1<<9)+1];

int main(int argc, const char * argv[]) {
    cin>>k;
    s[0][0]='+';
    for(int i=0;i<k;i++){
        int p=1<<i;
        for(int j=0;j<p;j++){
            for(int l=0;l<p;l++){
                s[j][l+p]=s[j][l];
                s[j+p][l]=s[j][l];
                s[j+p][l+p]='+'+'*'-s[j][l];
            }
        }
    }
    for (int i = 0; i < (1 << k); i++) {
        s[i][1 << k] = 0;
        
        printf("%s\n", s[i]);
    }
    return 0;
}