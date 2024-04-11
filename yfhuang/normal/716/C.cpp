//
//  main.cpp
//  C
//
//  Created by  on 9/17/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        if(i == 1){
            printf("2\n");
        }else{
            cout << (long long)(i) * (long long) (i + 1) *(long long)(i + 1) - (long long ) (i - 1) << endl;
        }
    }
    return 0;
}