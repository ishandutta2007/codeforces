//
//  main.cpp
//  B
//
//  Created by  on 15/11/21.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n,m;
int  f[100000+16];
int b[100000+16];
int a[100000+16];
struct num{
    int n;
    int fa;
}num[100000+16];

int main(int argc, const char * argv[]) {
    while(scanf("%d%d",&n,&m)==2){
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%d",&f[i]);
            num[f[i]].n++;
            num[f[i]].fa=i+1;
        }
        bool flag1=true,flag2=false;
        for(int i=0;i<m;i++){
            scanf("%d",&b[i]);
            a[i]=num[b[i]].fa;
            if(num[b[i]].n==0) flag1=false;
            else if(num[b[i]].n>=2) flag2=true;
        }
        if(!flag1){
            printf("Impossible\n");
        }
        else{
            if(flag2) printf("Ambiguity\n");
            else{
                printf("Possible\n");
                int first=1;
                for(int i=0;i<m;i++){
                    if(first){first=0;}
                    else printf(" ");
                    printf("%d",a[i]);
                }
            }
        }
    }
    return 0;
}