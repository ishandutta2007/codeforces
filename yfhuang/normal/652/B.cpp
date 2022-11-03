//
//  main.cpp
//  A
//
//  Created by  on 16/3/26.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1005;

int a[maxn];
int b[maxn];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int front=1,rear=n;
    int id=0;
    while(front<=rear){
        b[++id]=a[front];
        front++;
        if(front>rear) break;
        b[++id]=a[rear];
        rear--;
    }
    for(int i=1;i<=n;i++)
        cout<<b[i]<<' ';
    return 0;
}