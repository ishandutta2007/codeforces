//
//  main.cpp
//  J
//
//  Created by  on 16/3/14.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&m);
    if(n + m == 2) printf("1\n");
    else if(n + m < 5&&n + m > 2) printf("-1\n");
    else{
        int b = n*m/ 2;
        int x = 1;
        int y = b+1;
        for(int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if((i+j)%2==0){
                    printf("%d",y++);
                }else{
                    printf("%d",x++);
                }
                printf("%c",j==m?'\n':' ');
            }
        }
    }
    return 0;
}