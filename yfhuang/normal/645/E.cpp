//
//  main.cpp
//  E
//
//  Created by  on 16/3/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn=1000005;
const int maxk=30;
const int mod=1e9+7;

int dp[2*maxn],last[maxk];
int n,k;
char s[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    int m=strlen(s+1);
    fill(dp,dp+n+m+1,0);
    memset(last,0,sizeof(last));
    for(int i=1;i<=m;i++){
        int ch=s[i]-'a';
        if(!last[ch]){
            dp[i]=(dp[i-1]*2+1)%mod;
        }else{
            dp[i]=(dp[i-1]*2%mod-dp[last[ch]-1]+mod)%mod;
        }
        last[ch]=i;
    }
    for(int i=m+1;i<=m+n;i++){
        int loc=0;
        for(int j=0;j<k;j++){
            if(!last[j]){
                loc=j;
                break;
            }
            if(last[j]<last[loc]){
                loc=j;
            }
        }
        if(!last[loc]){
            dp[i]=(dp[i-1]*2+1)%mod;
        }else{
            dp[i]=(dp[i-1]*2%mod-dp[last[loc]-1]+mod)%mod;
        }
        last[loc]=i;
    }
    cout<<dp[m+n]+1<<endl;
    return 0;
}