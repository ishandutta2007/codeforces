//
//  main.cpp
//  A
//
//  Created by  on 15/12/20.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn=105;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int y;
    cin>>y;
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        pq.push(x);
    }
    int t=0;
    while(y>0){
        y-=pq.top();
        pq.pop();
        t++;
    }
    printf("%d\n",t);
    return 0;
}