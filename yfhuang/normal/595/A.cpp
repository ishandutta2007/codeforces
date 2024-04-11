//
//  main.cpp
//  A
//
//  Created by  on 15/11/9.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
int ans;

int main(int argc, const char * argv[]) {
    int n,m;
    int l1,l2;
    while(scanf("%d%d",&n,&m)==2){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d%d",&l1,&l2);
                if(l1||l2) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}