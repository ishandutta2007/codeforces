//
//  main.cpp
//  C
//
//  Created by  on 16/1/28.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[105];

int main(int argc, const char * argv[]) {
    scanf("%s",str+1);
    int l=strlen(str+1);
    for(int i=1;i<=l;i++){
        if(str[i]=='0'||str[i]=='8'){
            puts("YES");
            printf("%c\n",str[i]);
            return 0;
        }
    }
    for(int i=1;i<=l;i++){
        for(int j=i+1;j<=l;j++){
            if((10*(str[i]-'0')+str[j]-'0')%8==0){
                puts("YES");
                printf("%c%c\n",str[i],str[j]);
                return 0;
            }
        }
    }
    for(int i=1;i<=l;i++){
        for(int j=i+1;j<=l;j++){
            for(int k=j+1;k<=l;k++){
                if((100*(str[i]-'0')+10*(str[j]-'0')+str[k]-'0')%8==0){
                    puts("YES");
                    printf("%c%c%c",str[i],str[j],str[k]);
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}