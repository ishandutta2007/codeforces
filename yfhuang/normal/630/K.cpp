//
//  main.cpp
//  11
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
    long long a=n/2-n/6-n/15+n/3-n/10-n/21+n/5-n/14+n/7-n/35+n/30+n/42+n/105+n/70-n/2/3/5/7;
    cout<<n-a<<endl;
    return 0;
}