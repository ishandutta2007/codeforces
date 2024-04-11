//
//  main.cpp
//  B
//
//  Created by  on 16/2/21.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct f{
    int a,b;
    int type;
}fri[5005];


int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    char str[3];
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        if(str[0]=='M') fri[i].type=0;
        else fri[i].type=1;
        scanf("%d%d",&fri[i].a,&fri[i].b);
    }
    int ans=0;
    for(int i=1;i<=366;i++){
        int m=0,w=0;
        for(int j=1;j<=n;j++){
            if(fri[j].a<=i&&fri[j].b>=i){
                if(fri[j].type) m++;
                else w++;
            }
        }
        ans=max(ans,min(w,m)*2);
    }
    cout<<ans<<endl;
    return 0;
}