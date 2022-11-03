//
//  main.cpp
//  A
//
//  Created by  on 15/11/1.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char map[10][10];

int main(int argc, const char * argv[]) {
    while(scanf("%s",map[0])==1){
        for(int i=1;i<8;i++){
            scanf("%s",map[i]);
        }
        int p1, p2;
        bool flag=true;
        int ans1=0x3f3f3f3f,ans2=0x3f3f3f3f;
        for(int i=0;i<8;i++){
            p1=-1,p2=10;
            for(int j=0;j<8;j++)
                if(map[j][i]=='B') p1=j;
            flag=true;
            for(int j=p1;j<8;j++)
                if(map[j][i]=='W') flag=false;
            if(flag) ans1=min(ans1,7-p1);
            for(int j=7;j>=0;j--)
                if(map[j][i]=='W') p2=j;
            flag=true;
            for(int j=p2;j>=0;j--)
                if(map[j][i]=='B') flag=false;
            if(flag) ans2=min(ans2,p2);
        }
        //printf("%d%d",ans1,ans2);
        if(ans1<ans2) printf("B\n");
        else printf("A\n");
    }
    return 0;
}