//
//  main.cpp
//  D
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m,d;

const int maxm=2005;
const int mod=1e9+7;

char a[maxm],b[maxm];

void add(int &x,int y){
    x+=y;
    while(x>=mod) x-=mod;
}

int dp[maxm][maxm][2];

int get(char s[],int m,int d){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<s[0]-'0';i++)
        if(i!=d) dp[1][i%m][0]++;
    if(s[0]-'0'!=d) dp[1][(s[0]-'0')%m][1]=1;
    int l=strlen(s);
    for(int i=2;i<=l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<10;k++){
                if(i%2){
                    if(k==d) continue;
                }else{
                    if(k!=d) continue;
                }
                if(k<s[i-1]-'0') add(dp[i][(10*j+k)%m][0],dp[i-1][j][1]);
                if(k==s[i-1]-'0') add(dp[i][(10*j+k)%m][1],dp[i-1][j][1]);
                add(dp[i][(10*j+k)%m][0],dp[i-1][j][0]);
            }
        }
    }
    return (dp[l][0][0]+dp[l][0][1])%mod;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&m,&d);
    scanf("%s",a);
    scanf("%s",b);
    int l1=strlen(a);
    a[l1-1]--;
    for(int i=l1-1;i>=0;i--){
        while(a[i]<'0'){
            a[i]+=10;
            a[i-1]--;
        }
    }
    printf("%d",(get(b,m,d)-get(a,m,d)+mod)%mod);
    //for(int i=1;i<=l1;i++)
    //    num1[i]=a[i]-'0';
    //for(int i=1;i<=l1;i++)
    //    num2[i]=b[i]-'0';
    return 0;
}