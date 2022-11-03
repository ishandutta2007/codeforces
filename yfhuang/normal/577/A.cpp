//
//  main.cpp
//  A
//
//  Created by  on 16/1/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int n,x;

int main(int argc, const char * argv[]) {
    cin>>n>>x;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(x%i==0&&x/i<=n) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}