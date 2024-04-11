//
//  main.cpp
//  B
//
//  Created by  on 15/11/27.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[200008];
struct B{
    int val;
    int num;
    int id;
}b[200008];

bool cmp1( B x,B y){
    return x.val< y.val;
}

bool cmp2(B x,B y){
    return x.id<y.id;
}

int main(int argc, const char * argv[]) {
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            printf("%ld ",upper_bound(a+1, a+n+1,x)-(a+1));
        }
        printf("\n");
    }
    return 0;
}