//
//  main.cpp
//  B
//
//  Created by  on 15/12/26.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+16;

int pos[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pos[x]=i;
    }
    long long ans=0;
    for(int i=1;i<n;i++){
        ans+=abs(pos[i+1]-pos[i]);
    }
    cout<<ans<<endl;
    return 0;
}