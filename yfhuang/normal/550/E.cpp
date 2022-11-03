//
//  main.cpp
//  E
//
//  Created by  on 16/1/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1234567];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    if(n==1&&a[0]==0){
        puts("YES");
        puts("0");
        return 0;
    }
    if(a[n-1]==1){
        puts("NO");
        return 0;
    }
    n--;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] == 0) {
            puts("YES");
            printf("(");
            for (int j = 0; j < i; j++) {
                printf("%d->", a[j]);
            }
            printf("(%d->(", a[i]);
            for (int j = i + 1; j < n; j++) {
                printf("%d", a[j]);
                if (j + 1 < n) printf("->");
            }
            printf("))");
            puts(")->0");
            return 0;
        }
    }
    if (a[n - 1] == 1) {
        puts("YES");
        printf("(");
        for (int i = 0; i < n; i++) {
            if (i > 0) printf("->");
            printf("%d", a[i]);
        }
        printf(")->0");
        puts("");
    } else {
        puts("NO");
    }
    return 0;
}