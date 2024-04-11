//
//  main.cpp
//  B
//
//  Created by  on 15/11/5.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
long long x1,x2;
long long k,b;

struct a{
    long long left,right,ID;
}arr[100000+16],arr1[100000+16];;



bool cmp1(a m,a n){
    if(m.left!=n.left)
    return m.left<n.left;
    else return m.right<n.right;
}

bool cmp2(a m,a n){
    if(m.right!=n.right)
    return m.right<n.right;
    else return m.left<n.left;
}

int main(int argc, const char * argv[]) {
    bool f;
    while(scanf("%d",&n)==1){
        f=false;
        scanf("%I64d%I64d",&x1,&x2);
        for(int i=1;i<=n;i++){
            scanf("%I64d%I64d",&k,&b);
            arr[i].left=k*x1+b;
            arr[i].right=k*x2+b;
            arr[i].ID=i;
            arr1[i].left=k*x1+b;
            arr1[i].right=k*x2+b;
            arr1[i].ID=i;
        }
        sort(arr+1,arr+n+1,cmp1);
        sort(arr1+1,arr1+n+1,cmp2);
        for(int i=1;i<=n;i++){
            if(arr[i].ID!=arr1[i].ID) f=true;
        }
        if(f) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}