//
//  main.cpp
//  A
//
//  Created by  on 15/12/19.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=55;

int n;

int h[maxn*maxn],v[maxn*maxn];

bool h1[maxn],v1[maxn];

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++){
        scanf("%d%d",&h[i],&v[i]);
    }
    memset(h1,false,sizeof(h1));
    memset(v1,false,sizeof(v1));
    int first=1;
    for(int i=1;i<=n*n;i++){
        if(!h1[h[i]]&&!v1[v[i]]){
            if(first)first=0;
            else printf(" ");
            printf("%d",i);h1[h[i]]=true;v1[v[i]]=true;}
        
    }
    
    return 0;
}