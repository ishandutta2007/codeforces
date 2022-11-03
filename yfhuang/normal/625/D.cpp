//
//  main.cpp
//  D
//
//  Created by  on 16/2/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxl=100005;

char str[maxl];
int num[maxl];
char a[maxl];
int n;


bool ok(){
    for(int i=1;i<=n/2;){
       // printf("%d\n",i);
        if(num[i]==num[n+1-i]) i++;
        else if(num[i]==num[n+1-i]+1||num[i]==num[n+1-i]+11){
            num[i]--;
            num[i+1]+=10;
        }else if(num[i]==num[n+1-i]+10){
            num[n-i]--;
            num[n+1-i]+=10;
        }
        else return false;
    }
    //for(int i=1;i<=n;i++)
    //    printf("%d",num[i]);
    //printf("\n");
    if(n&1){
        if(num[n/2+1]<0||num[n/2+1]>18||num[n/2+1]%2==1) return false;
        a[n/2+1]=num[n/2+1]/2+'0';
    }
    for(int i=1;i<=n/2;i++){
        if(num[i]<0||num[i]>18) return false;
        a[i]=(num[i]+1)/2+'0';
        a[n+1-i]=(num[i])/2+'0';
    }
    a[n+1]='\0';
    return a[1]>'0';
}


int main(int argc, const char * argv[]) {
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++)
        num[i]=str[i]-'0';
    if(ok()) printf("%s\n",a+1);
    else if(str[1]=='1'&&n>1){
        n--;
        //printf("%s\n",str+1);
        //printf("%d %d\n",str[2]-'0',str[3]-'0');
        for(int i=1;i<=n;i++)
            num[i]=str[i+1]-'0';
        //printf("%d\n",num[2]);
        num[1]+=10;
        //printf("%d %d ",num[1],num[2]);
        if(ok()) printf("%s\n",a+1);
        else printf("0\n");
    }
    else printf("0\n");
    return 0;
}