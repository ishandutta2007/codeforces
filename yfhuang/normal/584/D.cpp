//
//  main.cpp
//  D
//
//  Created by  on 15/12/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int n;
    int i;
    cin>>n;
    for( i=0;i<=300;i++){
        if(is_prime(n-i)) break;
    }
    if(i==0) printf("1\n%d\n",n);
    else{
        if(i==2) printf("2\n2 %d\n",n-i);
        else{
            for(int j=2;j<=i/2;j++){
                if(is_prime(j)&&is_prime(i-j)){
                    printf("3\n%d %d %d\n",n-i,i-j,j);
                    break;
                }
            }
        }
    }
    return 0;
}