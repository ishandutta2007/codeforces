//
//  main.cpp
//  A
//
//  Created by  on 15/12/12.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1e5+10;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int a,b;
    priority_queue<int,vector<int>,greater<int> > pq;
    int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        pq.push(b);
        sum+=a*pq.top();
    }
    printf("%d\n",sum);
    return 0;
}