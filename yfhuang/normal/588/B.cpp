//
//  main.cpp
//  B
//
//  Created by  on 15/12/12.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n;
    cin>>n;
    //long long ans=1;
    for(long long i=2;i*i<=n;i++){
        if(n%(i*i)==0){
            n/=i;
            i=1;
        }
    }
    cout<<n<<endl;
    return 0;
}