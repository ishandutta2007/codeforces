//
//  main.cpp
//  B
//
//  Created by  on 16/1/15.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

const int maxn=1e5+5;

char a[maxn],b[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    int L=0;
    bool zero=false;
    for(int i=1;i<=n;i++){
        scanf("%s",a+1);
        int l=strlen(a+1);
        if(l==1&&a[l]=='0') zero=true;
        bool perfect=true;
        int cnt=0;
        for(int j=1;j<=l;j++){
            if(a[j]=='1') cnt++;
            else{
                if(a[j]!='0') perfect=false;
            }
        }
        if(cnt>1) perfect=false;
        if(!perfect){
            for(int j=1;j<=l;j++){
                b[j]=a[j];
            }
        }
        else L+=l-1;
    }
    if(!zero){
        int l=strlen(b+1);
        if(l==0) printf("1");
        for(int i=1;i<=l;i++)
            printf("%c",b[i]);
        for(int i=1;i<=L;i++)
            printf("0");
        printf("\n");
    }
    else printf("0\n");
    return 0;
}