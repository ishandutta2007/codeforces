//
//  main.cpp
//  A
//
//  Created by  on 16/1/11.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+5;

char a[maxn],b[maxn];

int main(int argc, const char * argv[]) {
    scanf("%s%s",a,b);
    int l1=strlen(a);
    int l2=strlen(b);
    int i;
    for( i=0;i<l1;i++)
        if(a[i]!='0') break;
    int j;
    for(j=0;j<l2;j++)
        if(b[j]!='0') break;
    if(l1-i>l2-j) printf(">");
    else if(l1-i<l2-j) printf("<");
    else{
        while(i<l1&&j<l2){
            if(a[i]>b[j]){
                printf(">");
                return 0;
            }
            else if(a[i]<b[j]){
                printf("<");
                return 0;
            }
            i++,j++;
        }
        printf("=");
    }
    return 0;
}