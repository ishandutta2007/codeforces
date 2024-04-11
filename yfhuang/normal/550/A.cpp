//
//  main.cpp
//  A
//
//  Created by  on 16/1/28.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    bool flag1=false,flag2=false;
    int cnt1=0,cnt2=0;
    char str[100005];
    scanf("%s",str);
    int l=strlen(str);
    for(int i=0;i<l-1;i++){
        if(str[i]=='A'&&str[i+1]=='B')
            cnt1++;
        if(str[i]=='B'&&str[i+1]=='A')
            cnt2++;
    }
    if(cnt1>=2&&cnt2>=2) puts("YES");
    else if(cnt1==1){
        for(int i=0;i<l-1;i++){
            if(str[i]=='A'&&str[i+1]=='B')
                str[i]=str[i+1]='C';
        }
        for(int i=0;i<l-1;i++){
            if(str[i]=='B'&&str[i+1]=='A'){
                puts("YES");
                return 0;
            }
        }
        puts("NO");
        return 0;
    }else if(cnt2==1){
        for(int i=0;i<l-1;i++){
            if(str[i]=='B'&&str[i+1]=='A')
                str[i]=str[i+1]='C';
        }
        for(int i=0;i<l-1;i++){
            if(str[i]=='A'&&str[i+1]=='B'){
                puts("YES");
                return 0;
            }
        }
        puts("NO");
        return 0;
    }
    else puts("NO");
    return 0;
}