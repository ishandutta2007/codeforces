//
//  main.cpp
//  A
//
//  Created by  on 8/29/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1005;

char s[maxn][10];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%s",s[i]);
    }
    bool flag = false;
    for(int i = 1;i <= n;i++){
        if(s[i][0] == 'O' && s[i][1] == 'O'){
            flag = true;
            s[i][0] = '+';
            s[i][1] = '+';
            break;
        }
        if(s[i][3] == 'O' && s[i][4] == 'O'){
            flag = true;
            s[i][3] = '+';
            s[i][4] = '+';
            break;
        }
    }
    if(flag){
        printf("YES\n");
        for(int i = 1;i <= n;i++){
            printf("%s\n",s[i]);
        }
    }else{
        printf("NO\n");
    }
    return 0;
}