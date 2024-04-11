//
//  main.cpp
//  A
//
//  Created by  on 16/3/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;


int main(int argc, const char * argv[]) {
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(n%2==1){
        if(n>a*b) printf("-1\n");
        else{
            int Demo = (n + 1) / 2;
            int repub = n - Demo;
            for(int i=1;i<=a;i++){
                for(int j=1;j<=b;j++){
                    if((i+j)%2==0){
                        if(Demo){
                            printf("%d",Demo * 2 - 1);
                            Demo--;
                        }else{
                            printf("0");
                        }
                    }else{
                        if(repub){
                            printf("%d",repub * 2);
                            repub--;
                        }else{
                            printf("0");
                        }
                    }
                    printf("%c",j==b?'\n':' ');
                }
            }
        }
    }else if(n%2==0){
        if(n > a * b) printf("-1\n");
        else{
            int Demo = n / 2;
            int repub = n / 2;
            for(int i=1;i<=a;i++){
                for(int j=1;j<=b;j++){
                    if((i+j)%2==0){
                        if(Demo){
                            printf("%d",Demo * 2 - 1);
                            Demo--;
                        }else{
                            printf("0");
                        }
                    }else{
                        if(repub){
                            printf("%d",repub * 2);
                            repub--;
                        }else{
                            printf("0");
                        }
                    }
                    printf("%c",j==b?'\n':' ');
                }
            }
        }
    }
    return 0;
}