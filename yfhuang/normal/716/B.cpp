//
//  main.cpp
//  B
//
//  Created by  on 9/17/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 50000 + 5;

char s[maxn];

int num[27];

int st[30];
int tot;

int main(int argc, const char * argv[]) {
    scanf("%s",s + 1);
    int len = strlen(s + 1);
    bool flag = false;
    for(int i = 1;i + 25 <= len;i++){
        memset(num,0,sizeof(num));
        for(int j = i;j <= i + 25;j++){
            if(s[j] == '?') num[26]++;
            else num[s[j] - 'A']++;
        }
        int sum = 0;
        bool f = true;
        for(int j = 0;j <= 26;j++){
            if(j < 26 && num[j] > 1) f = false;
            sum += num[j];
        }
        if(f && sum == 26){
            flag = true;
            tot = 0;
            for(int j = 0;j < 26;j++){
                if(num[j] == 0){
                    st[++tot] = j;
                }
            }
            for(int j = i;j <= i + 25;j++){
                if(s[j] == '?'){
                    s[j] = 'A' + st[tot];
                    tot--;
                }
            }
            break;
        }
    }
    for(int i = 1;i <= len;i++){
        if(s[i] == '?') s[i] = 'A';
    }
    if(flag){
        printf("%s\n",s + 1);
    }else{
        printf("-1\n");
    }
    return 0;
}