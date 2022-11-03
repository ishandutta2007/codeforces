//
//  main.cpp
//  B
//
//  Created by  on 16/1/22.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int c[10]={6,2,5,5,4,5,6,3,7,6};

long long cnt[10];

int main(int argc, const char * argv[]) {
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        int x=i;
        while(x>0){
            cnt[x%10]++;
            x/=10;
        }
    }
    long long ans=0;
    for(int i=0;i<10;i++){
        ans+=cnt[i]*c[i];
    }
    cout<<ans<<endl;
    return 0;
}