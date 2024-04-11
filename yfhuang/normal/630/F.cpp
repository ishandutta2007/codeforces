//
//  main.cpp
//  6
//
//  Created by  on 16/2/18.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main(int argc, const char * argv[]) {
    long long n;
    cin>>n;
    long long ans=n*(n-1)/2*(n-2)/3*(n-3)/2*(n-4)/10+n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)/720+n*(n-1)/2*(n-2)/3*(n-3)/2*(n-4)/10*(n-5)*(n-6)/6/7;
    //if(n==7) printf("29\n");
    cout<<ans<<endl;
    return 0;
}