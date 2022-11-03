//
//  main.cpp
//  C
//
//  Created by  on 15/12/29.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=505;
const int maxm=1005;

int w[maxn];
int b[maxm];
bool vis[maxn];
int a[maxn];

int n,m;

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int j=1;j<=m;j++)
        scanf("%d",&b[j]);
    long long ans=0;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            vis[i]=false;
        }
        for(int i=j-1;i>=1;i--){
            if(b[i]==b[j]){
                break;
            }
            if(vis[b[i]])
                continue;
            vis[b[i]]=true;
            ans+=w[b[i]];
        }
    }
    cout<<ans<<endl;
    return 0;
}