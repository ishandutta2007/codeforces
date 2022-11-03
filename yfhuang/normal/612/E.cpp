//
//  main.cpp
//  E
//
//  Created by  on 15/12/26.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

const int maxn=1e6+16;

int arr[maxn];
int ans[maxn];
bool vis[maxn];
int len[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int cur=i;
        int ln=0;
        while(!vis[cur]){
            ln++;
            vis[cur]=true;
            cur=arr[cur];
        }
        if(ln%2){
            cur=i;
            ln=(ln+1)/2;
            int c2=cur;
            for(int i=0;i<ln;i++){
                cur=arr[cur];
            }
            for(int i=0;i<ln;i++){
                ans[c2]=cur;
                ans[cur]=arr[c2];
                c2=arr[c2];
                cur=arr[cur];
            }
        }
        else{
            if(len[ln]==0){
                len[ln]=i;
            }
            else{
                int c1=len[ln];
                int c2=i;
                for(int i=0;i<ln;i++){
                    ans[c1]=c2;
                    ans[c2]=arr[c1];
                    c1=arr[c1];
                    c2=arr[c2];
                }
                len[ln]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(len[i]!=0){
            printf("-1\n");
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}