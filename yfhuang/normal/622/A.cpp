//
//  main.cpp
//  A
//
//  Created by  on 16/2/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;



int main(int argc, const char * argv[]) {
    long long n;
    cin>>n;
    long long a=sqrt(2.0*n);
    while(a*(a+1)>=2*n) a--;
    cout<<n-a*(a+1)/2<<endl;
    return 0;
}