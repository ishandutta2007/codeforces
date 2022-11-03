//
//  main.cpp
//  C
//
//  Created by  on 15/12/2.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[100005];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    scanf("%s",str);
    //int L=strlen(str);
    int change=0;
    for(int i=1;i<n;i++){
        if(str[i]!=str[i-1]) change++;
    }
    int ans=change+1;
    int same=0;
    for(int i=1;i<n;i++){
        if(str[i-1]==str[i])
            same++;
    }
    if(same>=2) ans+=2;
    else if(same==1) ans+=1;
    printf("%d\n",ans);
    return 0;
}