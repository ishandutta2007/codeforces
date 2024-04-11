//
//  main.cpp
//  B
//
//  Created by  on 15/11/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char strings[10000+10];
char stringss[10000+10];

int main(int argc, const char * argv[]) {
    scanf("%s",strings);
    int L=strlen(strings);
    for(int i=0;i<L;i++){
        stringss[i]=strings[i];
    }
    int t;
    int l,r,k;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&l,&r,&k);
        k=k%(r-l+1);
        for(int i=1,x=k;i<=r-l+1;i++,x+=1){
            int y;
            if(x<=r-l+1)  y=l-2+x;
            else  y=l-2+x-(r-l+1);
            if(y-k<l-1) stringss[y]=strings[y-k+r-l+1];
            else stringss[y]=strings[y-k];
        }
        for(int i=l-1;i<=r-1;i++){
            strings[i]=stringss[i];
        }
    }
    printf("%s\n",strings);
    return 0;
}