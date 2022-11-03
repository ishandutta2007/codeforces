//
//  main.cpp
//  C
//
//  Created by  on 16/2/19.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=1e5+5;

char str[N];
char ans[N];

int k,n;

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    long long maxdif=0;
    for(int i=1;i<=n;i++){
        maxdif+=max(str[i]-'a','z'-str[i]);
    }
    if(maxdif<k){
        printf("-1\n");
    }else{
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            int a=str[i]-'a';
            int b='z'-str[i];
            if(a>=b){
                if(a<=k){
                    ans[i]='a';
                    k-=a;
                }else{
                    ans[i]=str[i]-k;
                    k=0;
                }
            }else{
                if(b<=k){
                    ans[i]='z';
                    k-=b;
                }else{
                    ans[i]=str[i]+k;
                    k=0;
                }
            }
        }
        printf("%s",ans+1);
    }
    return 0;
}