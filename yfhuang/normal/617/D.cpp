//
//  main.cpp
//  D
//
//  Created by  on 16/1/24.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    long long x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(x1==x2&&x1==x3){
        printf("1\n");
        return 0;
    }else if(y1==y2&&y1==y3){
        printf("1\n");
        return 0;
    }else if(y1==y2&&y1!=y3){
        if(x3<max(x2,x1)&&x3>min(x1,x2)){
            printf("3\n");
            return 0;
        }else {
            printf("2\n");
            return 0;
        }
    }else if(y1==y3&&y1!=y2){
        if(x2<max(x3,x1)&&x2>min(x1,x3)){
            printf("3\n");
            return 0;
        }else {
            printf("2\n");
            return 0;
        }
    }else if(y3==y2&&y1!=y3){
        if(x1<max(x2,x3)&&x1>min(x3,x2)){
            printf("3\n");
            return 0;
        }else {
            printf("2\n");
        }
    }else if(x1==x2&&x1!=x3){
        if(y3>min(y1,y2)&&y3<max(y1,y2)){
            printf("3\n");
            return 0;
        }else{
            printf("2\n");
        }
    }else if(x1==x3&&x1!=x2){
        if(y2>min(y1,y3)&&y2<max(y1,y3)){
            printf("3\n");
            return 0;
        }else{
            printf("2\n");
        }
    }else if(x3==x2&&x1!=x3){
        if(y1>min(y3,y2)&&y1<max(y3,y2)){
            printf("3\n");
            return 0;
        }else{
            printf("2\n");
        }
    }else{
        printf("3\n");
        return 0;
    }
    
    return 0;
}