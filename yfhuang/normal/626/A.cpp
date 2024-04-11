//
//  main.cpp
//  A
//
//  Created by  on 16/2/14.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    char str[205];
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    long long cnt=0;
    for(int i=1;i<=n;i++){
        int x=0,y=0;
        for(int j=i;j<=n;j++){
            if(str[j]=='U') y++;
            else if(str[j]=='D') y--;
            else if(str[j]=='L') x--;
            else if(str[j]=='R') x++;
            if(x==0&&y==0) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}