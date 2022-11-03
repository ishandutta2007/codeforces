//
//  main.cpp
//  B
//
//  Created by  on 16/4/9.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    if(m <= n * 2){
        for(int i = 1;i <= m;i++){
            printf("%d ",i);
        }
    }else{
        for(int i = n * 2 + 1;i <= m;i++){
            printf("%d %d ",i,i - 2 * n);
        }
        for(int i = m + 1;i <= 4 * n;i++){
            printf("%d ",i - 2 * n);
        }
    }
    return 0;
}