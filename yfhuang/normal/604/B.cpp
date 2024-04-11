//
//  main.cpp
//  B
//
//  Created by  on 15/12/1.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k;
int s[100005];

bool ok(int x){
    int front=1,rear=n;
    int num=0;
    for(;rear>=front;){
        if(s[rear]>x) return false;
        if(rear>front&&s[rear]+s[front]<=x){
            rear--;
            front++;
            num++;
        }
        else{
            rear--;
            num++;
        }
    }
    if(num<=k) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
    }
    int L=0;
    int R=2*s[n];
    //printf("%d ",ok(12345));
    while(L<R){
        int mid=(L+R)>>1;
        if(ok(mid)) R=mid;
        else L=mid+1;
        //printf(" %d ",mid);
    }
    printf("%d\n",L);
    return 0;
}